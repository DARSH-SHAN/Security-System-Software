#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    int a, i=0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2],cp[2];

    // Creating Main Interface.
    cout<<"|___________Security System____________|"<<endl<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"|           1. Register                |"<<endl;
    cout<<"|           2. Login                   |"<<endl;
    cout<<"|           3. Change Password         |"<<endl;
    cout<<"|           4. End Program             |"<<endl;
    cout<<"|--------------------------------------|"<<endl<<endl;

    do
    {
        cout<<endl<<endl;
        cout<<"Enter your choice:- ";
        cin>>a;
        switch(a)
        {
            case 1:
            {
            // interface for Register page.
              cout<<"|--------------------------------------|"<<endl;
              cout<<"|***********     Register     *********|"<<endl;
              cout<<"|--------------------------------------|"<<endl<<endl;
              cout<<"Please Enter the Username:- ";
              cin>>name;
              cout<<"Please Enter the Password:- ";
              cin>>password0;
              cout<<"Please Enter Your Age:- ";
              cin>>age;

             //File Handling Operation has used to store the above user eneterd details.
             ofstream of1;
             of1.open("file.txt");
             if(of1.is_open())
             {
                of1<<name<<"\n";
                of1<<password0;
                cout<<"Registration Successful"<<endl;
             }
             break;
            }

            case 2:
            {
                i=0;

                //interface for Login page.
                cout<<"|------------------------------------|"<<endl;
                cout<<"|***********      Login     *********|"<<endl;
                cout<<"|------------------------------------|"<<endl<<endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"Please Enter the Username:- ";
                cin>>user;
                cout<<"Please Enter the Password:- ";
                cin>>pass;

                if(of2.is_open())
                {
                    while(!of2.eof())
                    {
                        while(getline(of2,text))
                        {
                            istringstream iss(text);//istringstream object is used to stream the string and store it using the extraction operator.
                            iss>>word;
                            creds[i]=word;
                            i++;                   
                        }
                        // below if statement is used to check the credentials are similar or not.
                        if(user==creds[0] && pass==creds[1])
                        {
                            cout<<"------Login Successful-------";
                            cout<<endl<<endl;
                            cout<<"Details:- "<<endl;
                            cout<<"Username: "+ name<<endl;
                            cout<<"Password: "+ pass<<endl;
                            cout<<"Age: "+ age<<endl;
                        }

                        else
                        {
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"|          1. Press 2 to Login                  |"<<endl;
                            cout<<"|          2. Press 3 to Change Password        |"<<endl;
                            break;
                        }
                    }
                }
                break;

            }

            case 3:
            {
                i=0;
                cout<<"-------------Change Password-----------"<<endl;

                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the Old Password:- ";
                cin>>old;
                cout<<"Enter your New Password:- ";
                cin>>password1;
                cout<<"Enter your New Password again:- ";
                cin>>password2;
                if(of0.is_open())
                {
                    while(!of0.eof())
                    {
                        while(getline(of0, text))
                        {
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }

                        if(old==cp[1])
                        {
                            ofstream of1;
                            of1.open("file.txt");
                            if(of1.is_open())
                            {
                                if(password1==password2)
                                {
                                    of1<<cp[1]<<"\n";
                                    of1<<password1;
                                    cout<<"Password Changed Successfully"<<endl;
                                }

                                else
                                {
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password do not match"<<endl;
                                }
                            }
                        }

                        else
                        {
                            cout<<"Please enter a valid Password"<<endl;
                            break;
                        }
                    }
                }
                break;
            }

            case 4:
            {
                cout<<"_____________*****Thank_you!*****____________";
                break;
            }

            default:
                cout<<"Enter a valid choice";
        }
        
    }

    while(a!=4);
    return 0;
}