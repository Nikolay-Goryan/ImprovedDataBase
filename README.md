## ImprovedDataBase


This project implements a data base which can contain the events that have happened on a given date.\
The programm can interact with the user using standart streams stdin and stdout.

Available commands are:

**Add Date Event** adds the event on a given date\
**Del condition** deletes the event on a given date that satisfy the **condition**\
**Last Date** prints the last event that happend not later than the given date\
**Find condition** finds and prints all the events that satisfy the **condition**\
**Print** prints all the existing events

The example of a condition:\
**date >= 2017-01-01 AND date < 2017-07-01 AND event == "sport**

#### Example:

**Input:**

Add 2017-11-21 Tuesday\
Add 2017-11-20 Monday\
Add 2017-11-21 Weekly meeting\
Print\
Find event != "Weekly meeting"\
Last 2017-11-30\
Del date > 2017-11-20\
Last 2017-11-30\
Last 2017-11-01

**Output:**

2017-11-20 Monday\
2017-11-21 Tuesday\
2017-11-21 Weekly meeting\
2017-11-20 Monday\
2017-11-21 Tuesday\
Found 2 entries\
2017-11-21 Weekly meeting\
Removed 2 entries\
2017-11-20 Monday\
No entries

