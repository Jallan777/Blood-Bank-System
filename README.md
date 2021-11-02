# Blood-Bank-System
NZ Blood Bank System
Objective: The objective of this assignment is to develop an application to store and retrieve information of blood donors and recipients (might include blood bank, hospital or patient). The app contains several screens, each might have relevant menu options.


1.	Introduction screen should include:
    
    •	Name of the blood bank application, information about NZ Blood Bank, contact details and login / registration option. 
    
    •	It must confirm the user category (donor or recipient) when login and registration (See the registration screen in Task 3).
    
    •	It can also be logged in and controlled by an administration account (See Task 8 for more details) 


2.	Donor’s screen should include: 
   
    •	A menu with the following options: 
        
        -	Procedure to donate blood 
       
        -	Benefits of blood donation
        
        -	Managing their information like updating their contact details, address and health status and booking for the donation.


3.	Donor’s registration screen should include:
    
    •	First name, last name, dob, nationality, ethnicity, gender known underlying conditions (heart, ADHD, diabetic, cancer, chickenpox etc…)  blood group (optional if they don’t know, include none in the field), contact no, email, physical address, last date of donation(optional), username  and password.  
    
    •	Registration data can be stored or retrieved from corresponding files. (For example: Donor_Registration file can store the donor’s data as like recipient...)


4.	Login screen should include: 
    
    •	Donors and Recipients login must be validated and verified with information stored in corresponding files (e.g. Donor_Registration or Recipient_Registration). 
    
    •	Provide Maximum three login attempts to access the system. Otherwise notify them login after some time


5. <I JUST REALISED NUMBER 5 IS MISSING ON MY WORD FILE>


6. Recipient’s screen should include:
    
    •	A menu with the following options:  
       
        -	Access donor’s information by blood group
        
        -	Access donors by blood group and location
        
        -	Potential donors contact details find by giving full name.


7. Recipient’s registration screen should include:
    
    •	Name of the hospital or name of the blood bank or Patient name
    
    •	Physical address
    
    •	Email
    
    •	Contact Num
    
    •	recipients_validation_status (valid registration to access blood).


8. Administration screen should include: 
    
    •	View the recipient information and donors’ information
    
    • Update the donor’s blood testing reports
    
    •	Donor’s report
    
    •	Report based on blood group
    
    •	Report based on location 
    
    •	Recipient report


9. Booking screen should include: 
    
    •	Booking for the donation must access the donor’s full name, dob, recent health condition, date, time, and time_availability_at_the_venue_of_donation.
    
    •	Time slot in between 9 to 4 pm, system should notify the donor if the slot taken by another. 
    
    
    •	Hint: The system is supposed to serve 01 people at a time. A time slot can be a fixed duration (e.g. 1 hour).  
