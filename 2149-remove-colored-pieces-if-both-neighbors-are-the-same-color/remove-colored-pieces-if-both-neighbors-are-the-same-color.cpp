class Solution {
public:
    bool winnerOfGame(string colors) {
        // 02.10.23 potd
        // Approach: Iterative Count

        // Initialize variables to keep track of consecutive plays by Alice and 
        // Bob, and a count variable for consecutive colors
        int alice_plays=0, bob_plays=0, count=0;

        // Loop through the string of colors starting from the second character
        for(int i=1; i<colors.size(); i++){
            // Check if the current color is the same as the previous one
            if(colors[i] == colors[i-1])
                count++;
            else{
            // If colors are different, it means the consecutive sequence has ended

                // Check the previous and update their score accordingly
                if(colors[i-1] == 'A')
                    alice_plays += max(0, count-1);
                else
                    bob_plays += max(0, count-1);

                // Reset the consecutive count to 0
                count=0;
            }
        }

        // After processing all plays, check the last play to update scores
        if(colors.back() == 'A')    
            alice_plays += max(0, count-1);
        else
            bob_plays += max(0, count-1);

        // Compare the total plays of Alice and Bob to determine the winner
        return alice_plays > bob_plays;




/*
        // APPROACH: Using a map and Nested Loop
        unordered_map<int,pair<char,char>> neigh;
        // neigh stores left and right neighbors of a character mapped with its index

        for(int i=1; i<colors.size()-1; i++){
            neigh[i].first = colors[i-1];
            neigh[i].second = colors[i+1];
        }

        bool turn = true;
        // true: Alice's turn, and false: Bob's turn

        while(true){
            bool moveMade = false;

            // If it's Alice's turn
            if(turn){
                for(int i=1; i<colors.size()-1; i++){
                    if(colors[i] == 'R' || colors[i] == 'B')    continue;
                    // R means Removed

                    // Else, curr char is 'A'
                    // If both the neighbors of 'A' are also 'A'
                    if(neigh[i].first == 'A' and neigh[i].second == 'A'){
                        colors[i] = 'R';
                        // neigh.erase(i);
                        moveMade = true;
                        break;
                    }
                }
            }
            // Else if it's Bob's turn
            else{
                for(int i=1; i<colors.size()-1; i++){
                    if(colors[i] == 'R' || colors[i] == 'A')    continue;
                    // R means Removed

                    // Else, curr char is 'B'
                    // If both the neighbors of 'B' are also 'B'
                    if(neigh[i].first == 'B' and neigh[i].second == 'B'){
                        colors[i] = 'R';
                        // neigh.erase(i);
                        moveMade = true;
                        break;
                    }
                }
            }

            if(!moveMade)
                return turn ? false : true;

            turn = !turn;
        }

        return false;
*/
    }
};