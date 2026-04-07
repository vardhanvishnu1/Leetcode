class Robot {
public:
    int w, h, p;
    int x = 0, y = 0;
    int dir = 0; // 0: East, 1: North, 2: West, 3: South
    bool moved = false;

    Robot(int width, int height) {
        w = width;
        h = height;
        p = 2 * (w - 1) + 2 * (h - 1);
    }
    
    void step(int num) {
        moved = true;
        num %= p;
        // If num % p is 0 but we actually called step, 
        // the robot technically "laps" back to (0,0) and faces South.
        if (num == 0) num = p; 

        while (num > 0) {
            if (dir == 0) { // East
                int steps = min(num, w - 1 - x);
                x += steps;
                num -= steps;
                if (num > 0) dir = 1;
            } else if (dir == 1) { // North
                int steps = min(num, h - 1 - y);
                y += steps;
                num -= steps;
                if (num > 0) dir = 2;
            } else if (dir == 2) { // West
                int steps = min(num, x);
                x -= steps;
                num -= steps;
                if (num > 0) dir = 3;
            } else if (dir == 3) { // South
                int steps = min(num, y);
                y -= steps;
                num -= steps;
                if (num > 0) dir = 0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        // Special case: if the robot is at (0,0) and has moved, 
        // it must be facing South (having just finished a lap).
        if (x == 0 && y == 0 && moved) return "South";
        
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};