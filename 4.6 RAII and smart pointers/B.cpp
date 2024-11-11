#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>

class Monitor {
private:
    using Ptr = ParticipantResults*;
    using ConstPtr = const ParticipantResults*;

    std::map<std::string, std::unique_ptr<ParticipantResults>> participants;
    std::map<std::string, std::vector<ConstPtr>> byTeam;
    std::vector<ConstPtr> allResults;

public:
    Monitor() = default;
    Monitor(const Monitor&) = delete;
    Monitor& operator=(const Monitor&) = delete;

    Ptr RegisterParticipant(const std::string& login, const std::string& team) {
        if (participants.find(login) != participants.end()) {
            throw std::invalid_argument("Participant is already registered");
        }

        auto participant = std::make_unique<ParticipantResults>(login, team);
        Ptr participantPtr = participant.get();

        participants[login] = std::move(participant);
        byTeam[team].push_back(participantPtr);
        allResults.push_back(participantPtr);

        return participantPtr;
    }

    Ptr GetParticipantResults(const std::string& login) {
        return participants.at(login).get();
    }

    ConstPtr GetParticipantResults(const std::string& login) const {
        return participants.at(login).get();
    }

    std::vector<ConstPtr> GetTeamResults(const std::string& team) const {
        return byTeam.at(team);
    }

    std::vector<ConstPtr> GetAllResults() const {
        return allResults;
    }
};