# Reflection 2
## Sprint Reflection
This sprint, our team focused on reading HFC in order to learn the foundation of what we needed to know to start our http server project.  We read HFC 3, 4, and 5, and worked through Allen's web server exercise.

I think as a team we're all a bit disappointed in the amount of work we did this sprint.  I think this is largely due to not meeting much outside of class and relying on individual work.  This next sprint we will have more meetings together and do work as a group or in pairs.  We used the trello board mostly to track who had done what readings, and it worked well and I tried to keep my part up to date.  It seemed at times that it was out of date and I would have to ask if a certain card is done or not, but it mostly reflected our state of progress.

## Exercises/Questions
We focused on reading quickly this sprint, so I didn't get to any of the HFC exercises.  While I didn't do the actual web_server exercise, I looked through all the solution code and tried to understand it.  I made several comments in the code to help me understand it, and I implemented a simple URL parsing example.
## Exam Question
Describe what an enum is and why you would use it.

An enum allows you to define a set of symbols that a certain type of variable can be.  For instance, if you need to store a day of the week, there are only seven different days that it could be, so it is not memory-efficient to store them in strings.  You could define a `day_of_week` enum where the only options are `MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY`.  C will store these symbols as numbers, so it takes up much less space than strings.

Source: Head First C Chapter 5