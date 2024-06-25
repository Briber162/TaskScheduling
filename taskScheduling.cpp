#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Global variables
unordered_map<int, vector<int>> taskMap; // Map to store tasks assigned to each node
queue<int> nodeExecutionOrder; // Queue to store nodes in the order they are inserted

// Function declarations
void addTask(int node_id, int task_id);
void runTask();
void rebalanceTasks();
void printTasks(int node_id);

// Function to assign a task to a node
void addTask(int node_id, int task_id) {
    taskMap[node_id].push_back(task_id);
    if (taskMap[node_id].size() == 1) {
        nodeExecutionOrder.push(node_id);
    }
}

// Function to execute tasks in the order nodes were inserted
void runTask() {
    // Rebalance tasks before execution
    rebalanceTasks();

    cout<<"Executing Tasks \n\n";
    while (!nodeExecutionOrder.empty()) {
        int node_id = nodeExecutionOrder.front();
        nodeExecutionOrder.pop();

        cout<<"Node "<<node_id<<" has executed Task : ";
        while (!taskMap[node_id].empty()) {
            int task_id = taskMap[node_id].front();
            taskMap[node_id].erase(taskMap[node_id].begin()); // Remove the executed task from the node's list

            cout<<task_id<<" ";
        }
        cout<<"\n";
    }
}

// Function to rebalance tasks among nodes
void rebalanceTasks() {
    int totalNodes = taskMap.size();
    if (totalNodes == 0) return;

    int totalTasks = 0;
    for (const auto& entry : taskMap) {
        totalTasks += entry.second.size();
    }

    int avgWorkLoad = totalTasks / totalNodes;

    // Get nodes in the order of insertion
    vector<int> nodes;
    queue<int> tempQueue = nodeExecutionOrder;
    while (!tempQueue.empty()) {
        nodes.push_back(tempQueue.front());
        tempQueue.pop();
    }

    //nodes vector store the nodes in the order , they should be executed
    for (int node_id : nodes) {

        //taskMap stores the task to be executed by that node (node_id : task_id1, task_id2..)
        while (taskMap[node_id].size() > avgWorkLoad) {

            int taskToMove = taskMap[node_id].back();
            taskMap[node_id].pop_back();

            // Find a node with fewer tasks than avgWorkLoad and assign the task to it
            for (int otherNodeId : nodes) {
                if (otherNodeId != node_id && taskMap[otherNodeId].size() <= avgWorkLoad) {
                    taskMap[otherNodeId].push_back(taskToMove);
                    cout <<"Moved Task "<<taskToMove<<" from Node "<<node_id<<" to Node "<<otherNodeId<<"\n";
                    break;
                }
            }
        }
    }

    cout<<"\nPrinting tasks after rebalancing: "<<"\n\n";
    for(int i=1;i<=nodeExecutionOrder.size();i++){
        printTasks(i);
    }
}

// Function to print all tasks associated with a node
void printTasks(int node_id) {
    if (taskMap.find(node_id) == taskMap.end()) {
        cout <<"Node "<< node_id <<" has no tasks assigned.\n";
        return;
    }

    cout<<"Tasks assigned to Node "<<node_id<< ": ";
    for (int task : taskMap[node_id]) {
        cout << task << " ";
    }
    cout<<"\n";
}

int main() {
    // Example usage
    addTask(1, 1);
    addTask(1, 2);
    addTask(2, 3);
    addTask(3, 4);
    addTask(1, 5);

    cout <<"\nInitial tasks assigned:"<<"\n\n";
    printTasks(1);
    printTasks(2);
    printTasks(3);
    cout << endl;

    cout<<"Rebalancing tasks and then executing tasks:"<<"\n\n";
    runTask();

    return 0;
}
