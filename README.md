# TaskScheduling

Implemented the below problem:

We have multiple node_ids and tasks which would be stored in a taskQueue.
Each node_id is to be assigned with a task using addTask function which is described below in detail.<br/>There would be a rebelanceTask function which would re-distribute tasks aong the available nodes in a distributed manner i.e each node should have less than or equal to averageLoad tasks. Average load is calculated at run time that is (total_tasks / total_nodes). <br/>
Then we have a function runTask which simulated the workinf of a task (in our case just printing them out)<br/>
# 1.	addTask(node_id, task_id) :
this function assigns a node with a task, a single node can have more than 1 task assigned to it.

There is another function
# 2.	 runTask()
It checks if the taskqueue has any elements and executes the task (you can just print the node_id and the task_id saying node_id has executed task_id)

There is another function:
# 3.	rebalanceTask()
what this does is it balances the number of tasks assigned to each node , i.e if a node is having more tasks than  the avgerageWorkLoad, then the rebalcning of tasks should take place. In other words if there are 3 nodes:
node_1 , node_2 , node_3 <br/>
and the tasks assigned to them are as: <br/>
node1: task1, task6 <br/>
node_2 : task2, task3 , task4 <br/>
node_3 : task5 <br/>
avg = total_no_of_tasks / total_nodes => 7 / 3 = 2 <br/>
So each node should be balanced such that each node has 2 tasks assigned to it

# 4.	printTasks(node_id):
this function prints all the tasks associated with the node_id

## The nodes are to be executed in the same order as they are inserted

