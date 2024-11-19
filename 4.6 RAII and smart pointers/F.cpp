#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr

class Document {
protected:
    const std::string Content;
public:
    Document(const std::string& s) : Content(s) {}
    virtual ~Document() = default; // Virtual destructor for proper cleanup of derived classes

    virtual void Save() const = 0; // Pure virtual function
};

class PlainTextDocument : public Document {
public:
    PlainTextDocument(const std::string& s) : Document(s) {}
    void Save() const override { // Polymorphic implementation
        std::cout << Content << "\n";
    }
};

class HTMLDocument : public Document {
public:
    HTMLDocument(const std::string& s) : Document(s) {}
    void Save() const override { // Polymorphic implementation
        std::cout << "<HTML><BODY>" << Content << "</BODY></HTML>\n";
    }
};

// The collection now stores smart pointers
using DocumentCollection = std::vector<std::unique_ptr<Document>>;

void AddDocument(const std::string& content, const std::string& type, DocumentCollection& collection) {
    if (type == "plain") {
        collection.push_back(std::make_unique<PlainTextDocument>(content));
    } else if (type == "html") {
        collection.push_back(std::make_unique<HTMLDocument>(content));
    } else {
        throw std::invalid_argument("Unknown document type");
    }
}

void PrintCollection(const DocumentCollection& collection) {
    for (const auto& doc : collection) {
        doc->Save(); // Polymorphic call
    }
}