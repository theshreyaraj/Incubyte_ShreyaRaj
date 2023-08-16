#include <iostream>
#include <vector>
using namespace std;
class LunarSpacecraft {
private:
    vector<int> position;
    string direction;

public:
    LunarSpacecraft(vector<int> initial_position, string initial_direction) {
        position = initial_position;
        direction = initial_direction;
    }

    void moveForward() {
        if (direction == "N")
            position[1]++;
        else if (direction == "S")
            position[1]--;
        else if (direction == "E")
            position[0]++;
        else if (direction == "W")
            position[0]--;
        else if (direction == "Up")
            position[2]++;
        else if (direction == "Down")
            position[2]--;
    }

    void moveBackward() {
        if (direction == "N")
            position[1]--;
        else if (direction == "S")
            position[1]++;
        else if (direction == "E")
            position[0]--;
        else if (direction == "W")
            position[0]++;
        else if (direction == "Up")
            position[2]--;
        else if (direction == "Down")
            position[2]++;
    }

    void turnLeft() {
        if (direction == "N")
            direction = "W";
        else if (direction == "S")
            direction = "E";
        else if (direction == "E")
            direction = "N";
        else if (direction == "W")
            direction = "S";
    }

    void turnRight() {
        if (direction == "N")
            direction = "E";
        else if (direction == "S")
            direction = "W";
        else if (direction == "E")
            direction = "S";
        else if (direction == "W")
            direction = "N";
    }

    void turnUp() {
        if (direction != "Up")
            direction = "Up";
    }

    void turnDown() {
        if (direction != "Down")
            direction = "Down";
    }

    vector<int> getPosition() {
        return position;
    }

    string getDirection() {
        return direction;
    }
};

vector<int> executeCommands(vector<int> starting_position, string initial_direction, vector<char> commands) {
    LunarSpacecraft spacecraft(starting_position, initial_direction);

    for (char command : commands) {
        if (command == 'f')
            spacecraft.moveForward();
        else if (command == 'b')
            spacecraft.moveBackward();
        else if (command == 'l')
            spacecraft.turnLeft();
        else if (command == 'r')
            spacecraft.turnRight();
        else if (command == 'u')
            spacecraft.turnUp();
        else if (command == 'd')
            spacecraft.turnDown();
    }

    return spacecraft.getPosition();
}

int main() {
    vector<int> starting_position(3);
    string initial_direction;
    string commands_str;

	//Input Initial Position
	cout << "Enter starting position (x y z): ";
	cin >> starting_position[0] >> starting_position[1] >> starting_position[2];
	
	//Input Initial Direction
	cout << "Enter initial direction (N, S, E, W, Up, Down): ";
	cin >> initial_direction;
	
	//Input Commands
	cout << "Enter commands (f, b, l, r, u, d): ";
	cin >> commands_str;
	
	vector<char> commands(commands_str.begin(), commands_str.end());
	vector<int> final_position = executeCommands(starting_position, initial_direction, commands);
    string final_direction = "N"; 

    cout << "Final Position: (" << final_position[0] << ", " << final_position[1] << ", " << final_position[2] << ")\n";
    cout << "Final Direction: " << final_direction << std::endl;

    return 0;
}
