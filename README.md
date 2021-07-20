# Class Scheduler Application

This is an application to **improve the effectiveness of the student class registration process**. Currently, students go through an enrollment process consisting of several rounds of enrollment periods where students jostle for spots left by the previous enrollment cohort. Each round affects the enrollment of the next round, and students often end up with a different schedule than what they were initially hoping for. This system has been used for many years and was good considering the technology at the time, but today, with our advanced algorithm and artificial intelligence technology, this very "human" system of enrollment could surely be replaced by a better, computer-driven system.

This application uses an algorithm to place the most students in the most classes they prefer, ideally outperforming and replacing the current class registration process.

## Components

### Controller Class
Controls the execution of the application. First, it populates 2 Directory instances using deques of Student and Section instances. Second, it calls upon the Scheduler algorithm sending the Directory of Students as a parameter, with an option for verbose feedback during the algorithm execution. Finally, it can reset the class schedules of Students and rosters of Sections if multiple iterations are intended to be executed.

### Directory/DirectoryIterator Class
A template, singleton class that encapsulates a map that links an integer key to a certain object of type T; in this application, there are two Directory instances, one holding type Section, one holding type Student. To access a certain Student or Section in this application, an object can call the singleton instance of that directory, and request a reference to an object based on its ID number. In essence, instead of using pointers to Students and Sections throughout the program, objects contain "references" via ID number and thus allows the Directory class to control all accesses to Student or Section objects, while also providing better memory safety.
The DirectoryIterator class provides a useful way to iterator over a set of objects in the Directory class.

### Scheduler Class
This class is the core of the application, and executes the actual scheduling algorithm. It takes a deque of Student ID numbers and attempts to enroll Students in their preferred classes. It also keeps track of successful enrollments and total enrollment attempts, allowing the Scheduler class to store algorithm accuracy.

### Scheduler Interface Class
This class simply wraps the Scheduler class, utilizing the adapter pattern, so that the interface used by the Controller class is consistent throughout development.

### Section Class
This class emulates a Section of a class offered by a university. It has a unique class ID number, and  stores a roster of students (that is filled by the Scheduler class). The Scheduler class also is responsible for scheduling the section, giving it one of a certain set of prespecified times. 

### Student Class
This class emulates a Student of a university. They have a unique student ID number and a list of preset class enrollment preferences. The Schduler class attempts to enroll the Student in as many of their preferred classes as possible, adding successfully enrolled classes to that student's class schedule.