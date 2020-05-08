# TaskCombo
An Application for starting Multiple Tasks at Once

## The Idea

While doing different kinds of work on the computer,it's sometimes necessary to open more than one tasks or applications.For example,to 
do video editing,someone may need to start a video-editing software, an audio-editing software and a file explorer.With TaskCombo it's 
possible to create many Sessions ( for example a Session for Video Editing,a Session for Office Work ,a session for Music Producing etc. 
)with many tasks(like software) for each , and then each time , start all of them at once.

### How to Use

After properly compiling and starting the excetuable file,use the command window to see the available options.When creating a new "Task"
inside a "Session"(you will need to enter this session first),make sure to properly enter the desired Task's full path as Location.For
example,let's say someone wants to create a new Task to start "Chrome.exe".Find the "Chrome.exe" file or it's shortcut,copy it's full 
path(Shift+Right Click->copy as path)and paste it when it asks for "Task Location".To start the combination of the "Tasks" you have
added inside a "Session", chose the option "Start Session" 

### Saving Data

For saving purposes,a .txt file named save_info.txt is created.When the user exits the application(using the appropriate command),all 
information are stored there.When the application is executed again,it reads all the previously saved information from this file.If this 
file is deleted,all saved data is lost.To properly save your changes after using the programme,make sure to use the option "Exit & Save"
instead of "killing it" with X Button

### Limitations

TaskCombo works ,currently,only in Windows.It's, also, in an initial form(no appropirate error handling or testing yet)
