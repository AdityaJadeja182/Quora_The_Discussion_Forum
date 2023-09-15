#include "bits/stdc++.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include "Forum.h"

using namespace std;
string user_session = "";
int totalDF = 0;
int const MAX_INDEX = 10;
Node *Array[MAX_INDEX];
Forum f(Array,MAX_INDEX);

void colour(int colour)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour);
}

void coordinate(int a,int b)
{
    COORD p;
    p.X=a;
    p.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

void fetchTitle()
{
    colour(4);
    coordinate(40,1);
    cout<<"******   *     *   *****   ******       *    "<<endl;
    coordinate(40,2);
    cout<<"*    *   *     *  *     *  *     *     * *   "<<endl;
    coordinate(40,3);
    cout<<"*  * *   *     *  *     *  ******     *****  "<<endl;
    coordinate(40,4);
    cout<<"*   **   *     *  *     *  *  *      *     * "<<endl;
    coordinate(40,5);
    cout<<"******    *****    *****   *    *   *       *"<<endl;
    coordinate(40,6);
    cout<<"      *                                      "<<endl;
    colour(7);
    return;
}
int displayAllForums(Node* Array[])
{
    colour(14);
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDiscussion Threads"<<endl<<endl;
    colour(7);
    int totalThreads=0;
    for(int i=0;i<MAX_INDEX;i++)
    {
        if(Array[i]->content!="")
        {
            totalThreads++;
            Node* temp = Array[i];
            colour(7);
            cout<<"[[ ";
            colour(14);
            cout<<i+1;
            colour(7);
            cout<<" ]] ";
            colour(14);
            cout<<temp->content<<endl;
            colour(7);
            cout<<"Created by:";
            colour(2);
            cout<<temp->user;
            colour(7);
            cout<<" on ";
            colour(8);
            cout<<temp->time<<endl<<endl;
            colour(7);
            temp = temp->nextNode;
            while(temp!=NULL)
            {
                colour(2);
                cout<<"\t"<<temp->user;
                colour(7);
                cout<<": ";
                colour(3);
                cout<<temp->content;
                colour(7);
                cout<<" on ";
                colour(8);
                cout<<temp->time<<endl;
                colour(7);
                temp=temp->nextNode;
            }
            cout<<endl;
        }
    }
    colour(7);
    cout<<"Total Threads Available: ";
    colour(2);
    cout<<totalThreads<<endl;
    colour(7);
    if(totalThreads!=0)
        return 1;
    else
        return 2;
}

int displayAllForumsByUser(Node* Array[],string username)
{
    colour(14);
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDiscussion Threads Created by ";
    colour(2);
    cout<<username<<endl<<endl;
    colour(7);
    int totalThreads=0;
    for(int i=0;i<MAX_INDEX;i++)
    {
        if(Array[i]->content!="" && Array[i]->user==username)
        {
            totalThreads++;
            Node* temp = Array[i];
            colour(7);
            cout<<"[[ ";
            colour(14);
            cout<<i+1;
            colour(7);
            cout<<" ]] ";
            colour(14);
            cout<<temp->content<<endl;
            colour(7);
            cout<<"Created by:";
            colour(2);
            cout<<temp->user;
            colour(7);
            cout<<" on ";
            colour(8);
            cout<<temp->time<<endl;
            colour(7);
            temp = temp->nextNode;
            while(temp!=NULL)
            {
                colour(2);
                cout<<"\t"<<temp->user;
                colour(7);
                cout<<": ";
                colour(3);
                cout<<temp->content;
                colour(7);
                cout<<" on ";
                colour(8);
                cout<<temp->time<<endl;
                colour(7);
                temp=temp->nextNode;
            }
            cout<<endl;
        }
    }
    colour(7);
    cout<<"Total Threads Available: ";
    colour(2);
    cout<<totalThreads<<endl;
    colour(7);
    if(totalThreads!=0)
        return 1;
    else
        return 2;
}

void home();

void login()
{

    struct user
    {
        string username;
        string password;
    };
    user s1;
    int s[3]={7,7,7};
    int counter=1;
    int flag=0;
    string msg = "";
    string uname="",pass="",cnfpass="";
    char key;
    while(1)
    {

    fetchTitle();
    coordinate(58,7);
    colour(s[0]);
    cout<<"1.Register"<<endl;
    coordinate(58,8);
    colour(s[1]);
    cout<<"2.Login"<<endl;
    coordinate(58,9);
    colour(s[2]);
    cout<<"3.Quit"<<endl<<endl;
    colour(7);

    if(flag==1)
    {
        coordinate(48,11);
        cout<<"Error: ";
        colour(4);
        cout<<msg<<endl<<endl;
        colour(7);
        flag=0;
    }
    else if(flag==2)
    {
        coordinate(48,11);
        cout<<"Success: ";
        colour(2);
        cout<<msg<<endl<<endl;
        colour(7);
        flag=0;
    }

    coordinate(0,13);
    cout<<"Select option(Use Up or Down Array Key to Select and Hit Enter): "<<endl<<endl;
    key = _getch();

    if(key==72 && (counter>=2 && counter<=3))
    {
        counter --;
    }
    if(key==80 && (counter>=1 && counter<=2))
    {
        counter ++;
    }
    if(key=='\r')
    {
        if(counter == 1)
        {
            flag=0;
            cout<<"Enter your username: ";
            cin>>uname;
            ifstream d;
            d.open("userdata.txt");

            d >> s1.username;
            d >> s1.password;
            while(!d.eof())
            {
                if(s1.username == uname)
                {
                    flag=1;
                    msg = "Username already taken.";
                }
                d >> s1.username;
                d >> s1.password;
            }
            d.close();
            if(flag==0)
            {
                cout<<"Enter your password: ";
                cin>>pass;
                cout<<"Re-Enter your password: ";
                cin>>cnfpass;
                if(pass == cnfpass)
                {
                    ofstream e;
                    e.open("userdata.txt",fstream::app);
                    e << uname;
                    e << " ";
                    e << pass;
                    e << endl;
                    e.close();
                    flag=2;
                    msg="Registration Successful!!";
                }
                else
                {
                    flag=1;
                    msg = "Passwords didn't match.";
                }
            }


        }
        else if(counter == 2)
        {
            flag=0;
            cout<<"Enter your username: ";
            cin>>uname;
            cout<<"Enter your password: ";
            cin>>pass;

            ifstream d;
            d.open("userdata.txt");

            d >> s1.username;
            d >> s1.password;

            while(!d.eof())
            {
                if(s1.username == uname && s1.password == pass)
                {
                    user_session = uname;
                    system("cls");
                    return;
                }
                d >> s1.username;
                d >> s1.password;
            }
            flag=1;
            msg="Login failed, Try Again!!";
            d.close();
        }
        else if(counter == 3)
        {
            system("cls");
            coordinate(48,1);
            colour(2);
            cout<<"Thank you for using our discussion forum!!"<<endl;
            colour(7);
            exit(0);
        }
        system("cls");
    }
        s[0]=7;
        s[1]=7;
        s[2]=7;

        if(counter==1)
        {
            s[0]=11;
        }
        if(counter==2)
        {
            s[1]=11;
        }
        if(counter==3)
        {
            s[2]=11;
        }

    }
}


int main()
{

    while(1)
    {
        if(user_session == "")
        {
            //cout<<"in"<<endl;
            login();
            home();
        }
        else
        {
            //cout<<"out"<<endl;
            home();
        }
    }
    return 0;
}

void fetchHomeScreen(int flag, int* s,string msg,bool showMenu)
{


        fetchTitle();

        coordinate(58,7);
        cout<<"Welcome, ";
        colour(2);
        cout<<user_session;
        colour(7);
        cout<<"!!"<<endl;

        if(showMenu)
        {
            coordinate(50,9);
            colour(s[0]);
            cout<<"1.Create New Discussion Thread"<<endl;
            coordinate(50,10);
            colour(s[1]);
            cout<<"2.Show My Discussion Threads "<<endl;
            coordinate(50,11);
            colour(s[2]);
            cout<<"3.Show All Discussion Threads"<<endl;
            coordinate(50,12);
            colour(s[3]);
            cout<<"4.Logout"<<endl;
            colour(7);
        }

        if(flag==1)
        {
            if(showMenu)
            {
                coordinate(48,14);
            }
            else
            {
                coordinate(48,9);
            }
            cout<<"Error: ";
            colour(4);
            cout<<msg<<endl<<endl;
            colour(7);
            flag=0;
        }
        else if(flag==2)
        {
            if(showMenu)
            {
                coordinate(48,14);
            }
            else
            {
                coordinate(48,9);
            }
            cout<<"Success: ";
            colour(2);
            cout<<msg<<endl<<endl;
            colour(7);
            flag=0;
        }
}

void home()
{
    int s[6]={7,7,7,7};
    int counter=1;
    int flag=0;
    string msg="";
    char key;

    while(1)
    {
        fetchHomeScreen(flag,s,msg,TRUE);

        coordinate(0,16);
        cout<<"Select option(Use Up or Down Array Key to Select and Hit Enter): "<<endl<<endl;
        key = _getch();

        if(key==72 && (counter>=2 && counter<=4))
        {
            counter --;
        }
        if(key==80 && (counter>=1 && counter<=3))
        {
            counter ++;
        }
        if(key=='\r')
        {

            if(counter==1)
            {
                //totalDF++;
                int i,a;
                for(i=0;i<MAX_INDEX;i++)
                {
                    if(Array[i]->content=="")
                    {
                        break;
                    }
                }
                if(i==MAX_INDEX+1)
                {
                    flag=1;
                    msg="No Space to Create A New Thread!!";
                }
                else
                {
                    string s;
                    cout<<"Enter The Topic For New Thread: ";
                    fflush(stdin);
                    getline(cin,s);
                    time_t now = time(0);
                    // convert now to string form
                    string time = ctime(&now);
                    a = f.addNode(s,user_session,time,i,Array,1);
                    if(a==1)
                    {
                        flag=1;
                        msg="Thread does not exist!! Try to Comment Again.";
                    }
                    else if(a==2)
                    {
                        flag=2;
                        msg="New Thread Created!!";
                    }
                    else if(a==3)
                    {
                        flag=2;
                        msg="Your comment is posted!!";
                    }


                }

            }
            if(counter==2)
            {

                system("cls");
                flag=0;
                int repeat = 0,type=0;
                while(repeat == 0)
                {

                    fetchHomeScreen(flag,s,msg,FALSE);
                    type=displayAllForumsByUser(Array,user_session);
                    if(type==1)
                    {
                        int o;
                        cout<<"Select option[1-Comment,2-Delete,3-Back]: ";
                        fflush(stdin);
                        cin>>o;
                        switch(o)
                        {
                            case 1:
                            {
                                int i,a;
                                string s;
                                cout<<"Enter The Topic No. Of Thread To Comment: ";
                                fflush(stdin);
                                cin>>i;
                                cout<<"Enter Your Comment: ";
                                fflush(stdin);
                                getline(cin,s);
                                time_t now = time(0);
                                // convert now to string form
                                string time = ctime(&now);
                                a=f.addNode(s,user_session,time,i-1,Array,2);
                                if(a==1)
                                {
                                    flag=1;
                                    msg="Thread does not exist!! Try to Comment Again.";
                                }
                                else if(a==2)
                                {
                                    flag=2;
                                    msg="New Thread Created!!";
                                }
                                else if(a==3)
                                {
                                    flag=2;
                                msg="Your comment is posted!!";
                                }
                                system("cls");
                                break;
                            }
                            case 2:
                            {
                                int i;
                                cout<<"Enter The Topic No. Of Thread To Delete: ";
                                fflush(stdin);
                                cin>>i;
                                if(Array[i-1]==NULL)
                                {
                                    flag=1;
                                    msg="Thread does not exist!!";
                                }
                                else
                                {
                                    if(Array[i-1]->user==user_session)
                                    {
                                        Array[i-1]->content="";
                                        Array[i-1]->user="";
                                        Array[i-1]->time="";

                                        Node* current = Array[i-1]->nextNode;
                                        Node* next=NULL;
                                        while (current != NULL)
                                        {
                                            next = current->nextNode;
                                            free(current);
                                            current = next;
                                        }
                                        flag=2;
                                        msg="Thread Deleted!!";

                                    }
                                    else
                                    {
                                        flag=1;
                                        msg="Access for Deletion Of This Thread Not Granted!!";
                                    }

                                }
                                system("cls");
                                break;
                            }
                            case 3:
                            {
                                flag=0;
                                msg="";
                                repeat = 1;
                                break;
                            }
                            default:
                            {
                                flag=1;
                                msg="Invalid Option Selected!!";
                                system("cls");
                                break;
                            }

                        }
                    }
                    else if(type==2)
                    {
                        int o;
                        cout<<"Press 1 to go back: ";
                        fflush(stdin);
                        cin>>o;
                        switch(o)
                        {
                            case 1:
                                {
                                    flag=0;
                                    msg="";
                                    repeat = 1;
                                    break;
                                }
                            default:
                                {
                                    flag=1;
                                    msg="Invalid Option Selected!!";
                                    system("cls");
                                    break;
                                }
                        }
                    }
                }
            }
            if(counter==3)
            {
                system("cls");
                int repeat = 0,type=0;
                while(repeat == 0)
                {
                    fetchHomeScreen(flag,s,msg,FALSE);
                    type=displayAllForums(Array);
                    if(type==1)
                    {
                        int o;
                        cout<<"Select option[1-Comment,2-Back]: ";
                        fflush(stdin);
                        cin>>o;
                        switch(o)
                        {
                            case 1:
                            {
                                int i,a;
                                string s;
                                cout<<"Enter The Topic No. Of Thread To Comment: ";
                                fflush(stdin);
                                cin>>i;
                                cout<<"Enter The Comment: ";
                                fflush(stdin);
                                getline(cin,s);
                                time_t now = time(0);
                                // convert now to string form
                                string time = ctime(&now);
                                a=f.addNode(s,user_session,time,i-1,Array,2);
                                if(a==1)
                                {
                                    flag=1;
                                    msg="Thread does not exist!! Try to Comment Again.";
                                }
                                else if(a==2)
                                {
                                    flag=2;
                                    msg="New Thread Created!!";
                                }
                                else if(a==3)
                                {
                                    flag=2;
                                    msg="Your comment is posted!!";
                                }
                                system("cls");
                                break;
                            }
                            case 2:
                            {
                                flag=0;
                                msg="";
                                repeat = 1;
                                break;
                            }
                            default:
                            {
                                flag=1;
                                msg="Invalid Option Selected!!";
                                system("cls");
                                break;
                            }

                        }
                    }
                    else if(type==2)
                    {
                        int o;
                        cout<<"Press 1 to go back: ";
                        fflush(stdin);
                        cin>>o;
                        switch(o)
                        {
                            case 1:
                                {
                                    flag=0;
                                    msg="";
                                    repeat = 1;
                                    break;
                                }
                            default:
                                {
                                    flag=1;
                                    msg="Invalid Option Selected!!";
                                    system("cls");
                                    break;
                                }
                        }
                    }

                }
            }
            if(counter==4)
            {
                user_session = "";
                system("cls");
                break;
            }
            system("cls");
        }
        s[0]=7;
        s[1]=7;
        s[2]=7;
        s[3]=7;
        if(counter==1)
        {
            s[0]=11;
        }
        if(counter==2)
        {
            s[1]=11;
        }
        if(counter==3)
        {
            s[2]=11;
        }
        if(counter==4)
        {
            s[3]=11;
        }

    }
}
