Algorithm:

Step 1:
I included the required libraries
declared required variables
created a structure name rescue for storing the information of Emergency requests

Step 2:
Main function:
first I displayed the choice of actions a user can select to do like register a request, display all requests, assign teams for the requests(In priority order),
Search for a specific request, summary of the requests in the storage. when the User clicks any of this options they can perform that action by the system calls the fuction.

Step 3:
Register request function:
It can hold limited number of requests only. The request id is generated automatically by incrementing the existing request id by 1.Then the user need to fill all the other
details manually such as location, people count, emergency level, needed resources and status is automatically set to "Pending.
The count for critical or normal cases is increased based on the emergency level for future use.
The records are sorted based on the priority (HIGH - critical), (LOW - normal) if it tied then it prioritize based on the people count (HIGH - greater count), (LOW - lesser count).
Send a Success message to the user.

Display function:
It traverse the records and display them one by one based in the order of priority.

Assigning function:
It help us to assign the team for the higher priority request and change the pending status and emergency level's counts.

Search function:
It ask for a searchId for searching a specific emergency request.
Then it searches the storage and show the requests details.

Summary function:
It summarizes the count of Critical pending requests, Normal pending Requests, how many request are assigned with a rescue team.

Step 4:
the main function runs until the user want to finish the their work. 




