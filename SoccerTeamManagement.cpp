#include<iostream>
#include<string>
using namespace std;

enum match_result
{
win,
loss,
draw
};

struct player
{
int player_id;
string player_name;
int goals_scored;
};

struct team
{
string team_name;
player players[4];
match_result results[3];
};

void input_players(player league_players[][4], int team_count, int players_per_team)
{
for (int team_index = 0; team_index < team_count; team_index++)
{
cout << "\n--- Enter Players for Team " << team_index + 1 << " ---\n";

    for (int player_index = 0; player_index < players_per_team; player_index++)
    {
        cout << "Player ID: ";
        cin >> league_players[team_index][player_index].player_id;

        cout << "Player Name: ";
        cin >> league_players[team_index][player_index].player_name;

        cout << "Goals Scored: ";
        cin >> league_players[team_index][player_index].goals_scored;
    }
}
}

void build_teams(team teams[], const player league_players[][4], int team_count, int players_per_team)
{
for (int team_index = 0; team_index < team_count; team_index++)
{
for (int player_index = 0; player_index < players_per_team; player_index++)
{
teams[team_index].players[player_index] =
league_players[team_index][player_index];
}
}
}

void input_results(team teams[], int team_count, int match_count)
{
int choice;

for (int team_index = 0; team_index < team_count; team_index++)
{
    cout << "\n--- Enter Results for " << teams[team_index].team_name << " ---\n";

    for (int match_index = 0; match_index < match_count; match_index++)
    {
        cout << "Match " << match_index + 1 << " (0-win,1-loss,2-draw): ";
        cin >> choice;

        if (choice == 0)
            teams[team_index].results[match_index] = win;
        else if (choice == 1)
            teams[team_index].results[match_index] = loss;
        else
            teams[team_index].results[match_index] = draw;
    }
}
}

void display_report(const team teams[], int team_count, int players_per_team, int match_count)
{
int highest_points = -1;
int highest_goals = -1;
int winner_index = 0;

cout << "\n========== SOCCER TOURNAMENT REPORT ==========\n";

for (int team_index = 0; team_index < team_count; team_index++)
{
    int total_goals = 0;
    int total_points = 0;

    cout << "\nTeam: " << teams[team_index].team_name << endl;
    cout << "Players:\n";

    for (int player_index = 0; player_index < players_per_team; player_index++)
    {
        cout << teams[team_index].players[player_index].player_id
             << " - "
             << teams[team_index].players[player_index].player_name
             << " Goals: "
             << teams[team_index].players[player_index].goals_scored
             << endl;

        total_goals += teams[team_index].players[player_index].goals_scored;
    }

    for (int match_index = 0; match_index < match_count; match_index++)
    {
        if (teams[team_index].results[match_index] == win)
            total_points += 3;
        else if (teams[team_index].results[match_index] == draw)
            total_points += 1;
    }

    cout << "Total Goals: " << total_goals << endl;
    cout << "Total Points: " << total_points << endl;

    if ((total_points > highest_points) ||
        (total_points == highest_points && total_goals > highest_goals))
    {
        highest_points = total_points;
        highest_goals = total_goals;
        winner_index = team_index;
    }
}

cout << "\n🏆 Tournament Winner: "
     << teams[winner_index].team_name << endl;

cout << "Points: " << highest_points
     << " | Goals: " << highest_goals << endl;
}

int main()
{
const int team_count = 3;
const int players_per_team = 4;
const int match_count = 3;

player league_players[team_count][players_per_team];
team teams[team_count];

for (int team_index = 0; team_index < team_count; team_index++)
{
    cout << "Enter Team " << team_index + 1 << " name: ";
    cin >> teams[team_index].team_name;
}

input_players(league_players, team_count, players_per_team);
build_teams(teams, league_players, team_count, players_per_team);
input_results(teams, team_count, match_count);
display_report(teams, team_count, players_per_team, match_count);

return 0;
}

