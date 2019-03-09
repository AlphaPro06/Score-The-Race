#include <iostream>
#include <string>
using namespace std;

int main() {
   while (true) {
      string outcome;
      cout << "Enter the race outcome: ";
      cin >> outcome;
      if (outcome == "done"){
          break;
      }
      // If the user entered "done", exit the program
      int numTeams = 0;       // The number of teams
      int scores['Z'+1] = {}; // scores[i] keeps track of the total score of team i
      int counts['Z'+1] = {}; // counts[i] keeps track of the number of runners on team i
      for (int i = 0; i < outcome.length(); ++i) { // For each runner in the race,
         // Increase the team's score by the runner's rank (the rank is 1 more than the index)
         scores[outcome[i]] += i + 1;
         // If it's the first runner of that particular team, update the total number of teams
         if(counts[outcome[i]] == 0){
             numTeams++;
         }
         counts[outcome[i]]++;
         // Update the number of runners on the team
      }
      // If the teams do not all have the same number of runners,
         // Print an error message and ask for input again (go back to the beginning of the loop)
         if (numTeams != outcome.length){
             cout << "Error. Input the runners again";
         }

      // Print the number of teams
      cout << "Teams: " << numTeams;
      // Print the number of runners on each team
          cout << "Each Team has: " << counts[outcome.length];
          string winningTeams = "";
          double winningScore = outcome.length() * outcome.length();
          for (char j = 'A'; j <= 'Z'; j++){
              if(scores[j] != 0){
                  cout << j << (double)scores[j] / counts[outcome.length];
                  if (scores[j] < winningScore){
                winningTeams = j;
                winningScore = scores[j];
              }
              else if (scores[j] == winningScore)
               winningTeams += j; 
          }
          cout << "The winning team" << (winningTeams.length() == 1 ? " is team " : "s are teams ");
          cout << winningTeams << " with score " << winningScore /  counts[outcome.length]<< endl;
      // For each letter from A-Z,
         // If that team participated,
            // Print the name of the team and its average score
            // Also keep track of which team(s) has the best score
      // Print the name of the winning team and its average score (if it's a tie, you may either pick one arbitrarily or print all of the winners)
   }
   return 0;
}