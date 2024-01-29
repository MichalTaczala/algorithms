#include <iostream>
#include <stack>

using namespace std;

class Task {
public:
    int time;
    int cumulatedTime;
    vector<int> to;
    bool isVisited;
    Task(int time) {
        this->time = time;
        this->cumulatedTime = time;
        isVisited = false;
    }
};


class Scheduler {
public:
    stack<int> stack;
    vector<Task*> tasks;
    Scheduler(vector<Task*> tasks) {
        this->tasks = tasks;
    }
    void relax(int idx){
        Task* currentTask = tasks.at(idx);
        currentTask->isVisited = true;
        for (int i=0;i<currentTask->to.size();i++){
            int nextTask = currentTask->to.at(i);
            if (tasks.at(nextTask)->isVisited)
                continue;
            relax(nextTask);

        }
        stack.push(idx);

    }
    void run() {
        int starting_node = 0;
        //building task
        for (int i=0;i<tasks.size();i++){
            if (tasks.at(i)->isVisited == false){
                relax(i);
            }
        }

        int max = 0;
        while (!stack.empty()){
            int stackTop = stack.top();
            Task* currentTask = tasks.at(stackTop);
            if (max < currentTask->cumulatedTime)
                max = currentTask->cumulatedTime;
            for (int i=0; i<currentTask->to.size();i++){
                Task* nextTask = tasks.at(currentTask->to.at(i));
                if (currentTask->cumulatedTime + nextTask->time > nextTask->cumulatedTime){
                    nextTask->cumulatedTime = currentTask->cumulatedTime + nextTask->time;
                    if (currentTask->cumulatedTime + nextTask->time > max) max = currentTask->cumulatedTime + nextTask->time;
                }
            }
            stack.pop();
        }
        cout << max << endl;
    }
};



int main() {
    // Your code here
    int z;
    cin >> z;
    for (int i = 0; i < z; i++) {
        int n,m;
        cin >> n >> m;
        vector<Task*> times;

        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            times.push_back(new Task(w));
        }

        for (int j = 0; j < m; j++) {
            int x,y;
            cin >> x >> y;
            times.at(x)->to.push_back(y);
            
        }
        Scheduler scheduler = Scheduler(times);
        scheduler.run();


    }

    return 0;
}