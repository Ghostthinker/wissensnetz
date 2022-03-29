
Security Questions provides administrator configurable challenge 
questions during the log in process.

Security questions lets the admin come up with questions, and then
lets the user submit their own answer to the question.

The log in form is altered to just show the username field and a 
submit button. Once a user enters their username, the module 
searches for their account, and randomly brings back one of their
security questions. They then need to provide the answer to the
questions as well as their password for authentication.

The user register form also gets a fieldset of questions so that 
the user can pick what question they want to answer and a textbox 
for their answer.

Once logged in, the user will see a tab on their account page 
called "Security Questions." This page lists the questions that 
they have chosen to answer, and provide a link for them to edit 
their answer.

NOTE: This is my first module that actually does something 
useful for more than just my client's project. Please test it out, 
and let me know of any issues. I will do my best to fix it.

****************************
INSTALLATION & CONFIGURATION
****************************
1. Download and enable the module just like any other module.
2. Go to Admin -> Configuration -> People -> Security Questions.
   (admin/config/people/security_questions)
3. Add questions for users to answer. These will be shown to users
   during the registration and login process. I would suggest having
   2 to 3 more than the number of required questions.
4. Go to the settings tab, and set the number of questions users will
   be required to answer. I would suggest no more than 3 or 4.