/*
              PASSKEY = 899889
                                            */

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cctype>
using namespace std;

bool containsOnlyAlphabets(string);
bool containsOnlyIntegers(string);

// To view one's profile
void viewProfile(int &index, string &profile);

// Headers
void header();
void fancyHeader();
void signHeader();
void signUpHeader();
void head();
void menuHeader(string menu);
void subMenuHeader(string subMenu);
void cursorHide();
void cursorShow();
void gotoxy(int x, int y);
void resizeConsole();

// Login Menu's
string signMenu();
bool signUp(string Name, string Pass, string Ro, string username[], string password[], string role[], int index);
string signIn(int &index, string &profile);

// User Menu's
int adminMenu();
int investorMenu();
int supplierMenu();
int employeeMenu();
int customerMenu();

// Admin's Options
int addEmp(int &index, int &addEmpIndex);
bool checkRole(string Ro);
int removeEmp(int &index, int &viewSerial, int &employeeSerial);
int viewEmployees(int &index, int &viewSerial, int &employeeSerial);
int addItem(int &itemIndex);
int removeItem(int &itemIndex);
int updateItem(int &index, int &itemIndex);
int viewItems(int &itemIndex);
int addOrUpdateSalary(int &index, int &viewSerial, int &employeeSerial);
int addInvestor(int &index);
int discount(int &itemIndex);
void viewFeedback();
void logout();

// Investor's Options
int changePass(int &index, string &profile);
void viewRevenue(int &profit);
void SuppliersProfiles(int &index, int &viewSerial);

// Supplier's Options
int enterProducts(int &inventoryIndex);
int offerDiscount(int &inventoryIndex);
int checkReceiving(int &inventoryIndex, int &balance);
int withDrawBalance(int &balance);
int viewInventory(int &inventoryIndex);

// Employee Functions
void inventoryToSale(int &index, int &inventoryIndex, int &profit, int &itemIndex);
void viewEmployeeProfile(int &index, string &profile);

// Customer Functions
int itemsToCart(int &itemIndex, int &cartIndex);
int viewBill(int &cartIndex);
int giveFeedback();

// Invalid
void invalidUser();
void invalidOption();
void invalidCredential();
void invalidSerialNo();

// Press Key
void pressKey();

// Secret Key
string secretKey = "899889";

// Indexes
int excellent = 0, good = 0, bad = 0, worst = 0;
int x1 = 10, x2 = 20, x3 = 30, x4 = 40, x5 = 50, x6 = 60, x7 = 70, x8 = 80;
int y1 = 10, y2 = 20, y3 = 30, y4 = 40, y5 = 50, y6 = 60, y7 = 70;

// Global Variables
string username[100];
string password[100];
string role[100];
string addEmployeeUser[100];
string addEmployeePass[100];
string addEmployeeSalary[100];
string itemName[100];
string inventoryProduct[100];
string inventoryPrice[100];
string inventoryQuantity[100];
string itemPrice[100];
string itemQuantity[100];
string cartName[100];
string cartPrice[100];
string cartQuantity[100];

int main()
{
    // Indexes
    int index = 0;
    int addEmpIndex = 0;
    int itemIndex = 0;
    int inventoryIndex = 0;
    int cartIndex = 0;
    int viewSerial = 1;
    int employeeSerial = 0;

    bool temp = false;

    // Some variables used ni multiples functions
    string profile = "";
    int balance = 0;
    int profit = 0;

    resizeConsole();
    cursorHide();
    fancyHeader();
    while (true)
    {
        string Name, Pass, Ro;
        bool exitLoop = false;

        string sign = signMenu();

        // Sign Up Menu
        if (sign == "1")
        {
            string passkey;

            signUpHeader();
            gotoxy(46, 22);
            cout << ">>> Enter Role (ADMIN, INVESTOR, SUPPLIER, EMPLOYEE, CUSTOMER): ";
            getline(cin, Ro);

            // Convert the Role to uppercase
            for (int i = 0; i < Ro.length(); i++)
            {
                Ro[i] = toupper(Ro[i]);
            }

            if (checkRole(Ro))
            {
                // Check if role is admin get passkey. Otherwise there is no need.
                if (Ro == "ADMIN" || Ro == "INVESTOR")
                {
                    gotoxy(46, 24);
                    cout << ">>> Enter Pass Key: ";
                    getline(cin, passkey);

                    if (passkey == secretKey)
                    {
                        gotoxy(46, 26);
                        cout << ">>> Enter Username: ";
                        getline(cin, Name);
                        gotoxy(46, 28);
                        cout << ">>> Enter Password: ";
                        getline(cin, Pass);

                        bool answer = signUp(Name, Pass, Ro, username, password, role, index);

                        if (answer == true)
                        {
                            username[index] = Name;
                            password[index] = Pass;
                            role[index] = Ro;
                            index++;
                            gotoxy(46, 30);
                            cout << "\e[0;92mSuccessfully Registered....\e[0m";
                            Sleep(1000);
                        }
                        else
                        {
                            gotoxy(46, 30);
                            invalidUser();
                        }
                    }
                    else
                    {
                        gotoxy(46, 26);
                        cout << "\e[0;31mInvalid passKey...\e[0m";
                        Sleep(1000);
                    }
                }
                else
                {
                    gotoxy(46, 24);
                    cout << ">>> Enter Username: ";
                    getline(cin, Name);
                    gotoxy(46, 26);
                    cout << ">>> Enter Password: ";
                    getline(cin, Pass);

                    bool answer = signUp(Name, Pass, Ro, username, password, role, index);

                    if (answer == true)
                    {
                        username[index] = Name;
                        password[index] = Pass;
                        role[index] = Ro;
                        index++;
                        gotoxy(46, 28);
                        cout << "\e[0;92mSuccessfully Registered....\e[0m";
                        Sleep(1000);
                    }
                    else
                    {
                        gotoxy(46, 28);
                        invalidUser();
                    }
                }
            }
            else
            {
                gotoxy(46, 24);
                cout << "\e[0;31mInvalid Role...\e[0m";
                Sleep(1000);
            }
        }

        // Sign In Menu
        else if (sign == "2")
        {
            string result1 = signIn(index, profile);
            while (!exitLoop)
            {
                if (result1 == "admin")
                {
                    menuHeader(" Admin Menu");
                    int result2 = adminMenu();

                    switch (result2)
                    {
                    case 1:
                        addEmp(index, addEmpIndex);
                        temp = true;
                        break;
                    case 2:
                        removeEmp(index, viewSerial, employeeSerial);
                        break;
                    case 3:
                        viewEmployees(index, viewSerial, employeeSerial);
                        break;
                    case 4:
                        addItem(itemIndex);
                        break;
                    case 5:
                        removeItem(itemIndex);
                        break;
                    case 6:
                        updateItem(index, itemIndex);
                        break;
                    case 7:
                        viewItems(itemIndex);
                        break;
                    case 8:
                        addOrUpdateSalary(index, viewSerial, employeeSerial);
                        break;
                    case 9:
                        addInvestor(index);
                        break;
                    case 10:
                        discount(itemIndex);
                        break;
                    case 11:
                        viewFeedback();
                        break;
                    case 12:
                        logout();
                        exitLoop = true;
                        break;
                    case 13:
                        return 0;
                    default:
                        if (temp)
                        {
                            break;
                        }
                        gotoxy(x6 + 5, y4);
                        invalidOption();
                    }
                }
                else if (result1 == "investor")
                {
                    menuHeader("Investor Menu");
                    int result2 = investorMenu();

                    switch (result2)
                    {
                    case 1:
                        viewProfile(index, profile);
                        break;
                    case 2:
                        changePass(index, profile);
                        break;
                    case 3:
                        viewEmployees(index, viewSerial, employeeSerial);
                        break;
                    case 4:
                        viewRevenue(profit);
                        break;
                    case 5:
                        SuppliersProfiles(index, viewSerial);
                        break;
                    case 6:
                        viewItems(itemIndex);
                        break;
                    case 7:
                        addItem(itemIndex);
                        break;
                    case 8:
                        removeItem(itemIndex);
                        break;
                    case 9:
                        logout();
                        exitLoop = true;
                        break;
                    case 10:
                        return 0;
                    default:
                        invalidOption();
                        break;
                    }
                }
                else if (result1 == "supplier")
                {
                    menuHeader("Supplier Menu");
                    int result2 = supplierMenu();

                    switch (result2)
                    {
                    case 1:
                        viewProfile(index, profile);
                        break;
                    case 2:
                        enterProducts(inventoryIndex);
                        break;
                    case 3:
                        offerDiscount(inventoryIndex);
                        break;
                    case 4:
                        checkReceiving(inventoryIndex, balance);
                        break;
                    case 5:
                        withDrawBalance(balance);
                        break;
                    case 6:
                        viewItems(itemIndex);
                        break;
                    case 7:
                        logout();
                        exitLoop = true;
                        break;
                    case 8:
                        return 0;
                    default:
                        invalidOption();
                        break;
                    }
                }
                else if (result1 == "employee")
                {
                    menuHeader("Employee Menu");
                    int result2 = employeeMenu();

                    switch (result2)
                    {
                    case 1:
                        viewEmployeeProfile(index, profile);
                        break;
                    case 2:
                        changePass(index, profile);
                        break;
                    case 3:
                        viewInventory(inventoryIndex);
                        break;
                    case 4:
                        inventoryToSale(index, inventoryIndex, profit, itemIndex);
                        break;
                    case 5:
                        viewItems(itemIndex);
                        break;
                    case 6:
                        addItem(itemIndex);
                        break;
                    case 7:
                        removeItem(itemIndex);
                        break;
                    case 8:
                        updateItem(index, itemIndex);
                        break;
                    case 9:
                        logout();
                        exitLoop = true;
                        break;
                    case 10:
                        return 0;
                    default:
                        invalidOption();
                        break;
                    }
                }
                else if (result1 == "customer")
                {
                    menuHeader("Customer Menu");
                    int result2 = customerMenu();

                    switch (result2)
                    {
                    case 1:
                        viewProfile(index, profile);
                        break;
                    case 2:
                        changePass(index, profile);
                        break;
                    case 3:
                        viewItems(itemIndex);
                        break;
                    case 4:
                        itemsToCart(itemIndex, cartIndex);
                        break;
                    case 5:
                        viewBill(cartIndex);
                        break;
                    case 6:
                        giveFeedback();
                        break;
                    case 7:
                        logout();
                        exitLoop = true;
                        break;
                    case 8:
                        return 0;
                    default:
                        invalidOption();
                        break;
                    }
                }
                else if (result1 == "invalid")
                {
                    gotoxy(x6 + 6, y2 + 8);
                    invalidUser();
                    break;
                }
            }
        }
        else if (sign == "3")
        {
            return 0;
        }
        else
        {
            gotoxy(59, 29);
            invalidOption();
        }
    }
}

// Header's

void header()
{
    system("cls");
    cout << "\n\e[0;32m";
    gotoxy(10, 1);
    cout << "__|0|_____________________________________________________________________________________________________________________________________|0|__" << endl;
    gotoxy(10, 2);
    cout << "__   _____________________________________________________________________________________________________________________________________   __" << endl;
    gotoxy(10, 3);
    cout << "  | |                                                                                                                                     | |  " << endl;
    gotoxy(10, 4);
    cout << "  | |   ooooooo8      o      oooooooooo  ooooooooo  ooooooooooo oooo   oooo    ooooooooooo oooooooooo  ooooooooooo  oooooooo8 ooooo ooooo | |  " << endl;
    gotoxy(10, 5);
    cout << "  | | o888    88     888      888    888  888    88o 888    88   8888o  88      888    88   888    888  888    88  888         888   888  | |  " << endl;
    gotoxy(10, 6);
    cout << "  | | 888    oooo   8  88     888oooo88   888    888 888ooo8     88 888o88      888ooo8     888oooo88   888ooo8     888oooooo  888ooo888  | |  " << endl;
    gotoxy(10, 7);
    cout << "  | | 888o    88   8oooo88    888  88o    888    888 888    oo   88   8888      888         888  88o    888    oo          888 888   888  | |  " << endl;
    gotoxy(10, 8);
    cout << "  | |  888ooo888 o88o  o888o o888o  88o8 o888ooo88  o888ooo8888 o88o    88     o888o       o888o  88o8 o888ooo8888 o88oooo888 o888o o888o | |  " << endl;
    gotoxy(10, 9);
    cout << "  | |                                                                                                                                     | |  " << endl;
    gotoxy(10, 10);
    cout << "  | |                       ooooooo  oooooooooo    ooooooo8      o      oooo   oooo ooooo  oooooooo8  oooooooo8                           | |  " << endl;
    gotoxy(10, 11);
    cout << "  | |                     o888   888o 888    888 o888    88     888      8888o  88   888 o888     88 888                                  | |  " << endl;
    gotoxy(10, 12);
    cout << "  | |                     888     888 888oooo88  888    oooo   8  88     88 888o88   888 888          888oooooo                           | |  " << endl;
    gotoxy(10, 13);
    cout << "  | |                     888o   o888 888  88o   888o    88   8oooo88    88   8888   888 888o     oo         888                          | |  " << endl;
    gotoxy(10, 14);
    cout << "  | |                       88ooo88  o888o  88o8  888ooo888 o88o  o888o o88o    88  o888o 888oooo88  o88oooo888                           | |  " << endl;
    gotoxy(10, 15);
    cout << "__| |_____________________________________________________________________________________________________________________________________| |__" << endl;
    gotoxy(10, 16);
    cout << "__   _____________________________________________________________________________________________________________________________________   __" << endl;
    gotoxy(10, 17);
    cout << "  | |                                                                                                                                     | |  " << endl;
    cout << "\e[0m";
}

void fancyHeader()
{
    system("cls");
    cout << "\n\e[0;32m";
    gotoxy(10, 1);
    Sleep(100);
    cout << "__|0|_____________________________________________________________________________________________________________________________________|0|__" << endl;
    gotoxy(10, 2);
    Sleep(100);
    cout << "__   _____________________________________________________________________________________________________________________________________   __" << endl;
    gotoxy(10, 3);
    Sleep(100);
    cout << "  | |                                                                                                                                     | |  " << endl;
    gotoxy(10, 4);
    Sleep(100);
    cout << "  | |   ooooooo8      o      oooooooooo  ooooooooo  ooooooooooo oooo   oooo    ooooooooooo oooooooooo  ooooooooooo  oooooooo8 ooooo ooooo | |  " << endl;
    gotoxy(10, 5);
    Sleep(250);
    cout << "  | | o888    88     888      888    888  888    88o 888    88   8888o  88      888    88   888    888  888    88  888         888   888  | |  " << endl;
    gotoxy(10, 6);
    Sleep(500);
    cout << "  | | 888    oooo   8  88     888oooo88   888    888 888ooo8     88 888o88      888ooo8     888oooo88   888ooo8     888oooooo  888ooo888  | |  " << endl;
    gotoxy(10, 7);
    Sleep(200);
    cout << "  | | 888o    88   8oooo88    888  88o    888    888 888    oo   88   8888      888         888  88o    888    oo          888 888   888  | |  " << endl;
    gotoxy(10, 8);
    Sleep(25);
    cout << "  | |  888ooo888 o88o  o888o o888o  88o8 o888ooo88  o888ooo8888 o88o    88     o888o       o888o  88o8 o888ooo8888 o88oooo888 o888o o888o | |  " << endl;
    gotoxy(10, 9);
    Sleep(20);
    cout << "  | |                                                                                                                                     | |  " << endl;
    gotoxy(10, 10);
    Sleep(10);
    cout << "  | |                       ooooooo  oooooooooo    ooooooo8      o      oooo   oooo ooooo  oooooooo8  oooooooo8                           | |  " << endl;
    gotoxy(10, 11);
    Sleep(10);
    cout << "  | |                     o888   888o 888    888 o888    88     888      8888o  88   888 o888     88 888                                  | |  " << endl;
    gotoxy(10, 12);
    Sleep(10);
    cout << "  | |                     888     888 888oooo88  888    oooo   8  88     88 888o88   888 888          888oooooo                           | |  " << endl;
    gotoxy(10, 13);
    Sleep(10);
    cout << "  | |                     888o   o888 888  88o   888o    88   8oooo88    88   8888   888 888o     oo         888                          | |  " << endl;
    gotoxy(10, 14);
    Sleep(10);
    cout << "  | |                       88ooo88  o888o  88o8  888ooo888 o88o  o888o o88o    88  o888o 888oooo88  o88oooo888                           | |  " << endl;
    gotoxy(10, 15);
    Sleep(5);
    cout << "__| |_____________________________________________________________________________________________________________________________________| |__" << endl;
    gotoxy(10, 16);
    Sleep(5);
    cout << "__   _____________________________________________________________________________________________________________________________________   __" << endl;
    gotoxy(10, 17);
    cout << "  | |                                                                                                                                     | |  " << endl;
    cout << "\e[0m";
}

void signHeader()
{
    int x = 52;
    int y = 17;

    gotoxy(x, y = y + 1);
    cout << "\e[0;32m   ________________________________________________" << endl;
    gotoxy(x, y = y + 1);
    cout << "  |  ____________________________________________  |" << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                            | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                            | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                            | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                            | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                            | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                            | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                            | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                            | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                            | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                            | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |____________________________________________| |" << endl;
    gotoxy(x, y = y + 1);
    cout << "  |________________________________________________|\e[0m" << endl;
}

void signUpHeader()
{
    int x = 25;
    int y = 17;

    gotoxy(x, y = y + 1);
    cout << "\e[0;32m   __________________________________________________________________________________________________" << endl;
    gotoxy(x, y = y + 1);
    cout << "  |  ______________________________________________________________________________________________  |" << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |                                                                                              | |  " << endl;
    gotoxy(x, y = y + 1);
    cout << "  | |______________________________________________________________________________________________| |" << endl;
    gotoxy(x, y = y + 1);
    cout << "  |__________________________________________________________________________________________________|\e[0m" << endl;
}

void head()
{
    system("cls");
    header();
}

void menuHeader(string menu)
{
    int x = 65, y = 18;

    cursorHide();
    head();
    cout << "\u001b[32;1m";

    // header
    gotoxy(x + 10, y);
    cout << " -----------------" << endl;
    gotoxy(x + 10, y + 1);
    cout << "|                 |" << endl;
    gotoxy(x + 10, y + 2);
    cout << " -----------------" << endl;
    cout << "\u001b[0m";
    gotoxy(x + 13, y + 1);
    cout << menu;

    gotoxy(0, y + 3);
    cout << "________________________________________________________________________________________________________________________________________________________________________";
    gotoxy(0, y + 4);
    cout << "                                                                                                        ";

    cursorShow();
}

void subMenuHeader(string subMenu)
{
    int x = 65, y = 18;

    cursorHide();
    head();

    // Sub Menu
    gotoxy(x + 10, y + 1);
    cout << subMenu;

    gotoxy(0, y + 3);
    cout << "____________________________________________________________________________________________________________________________________________________________________________________________";
    gotoxy(0, y + 4);
    cout << "                                                                                                        ";

    cursorShow();
}

// Miscalenous Functions

void cursorHide()
{
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

void cursorShow()
{
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void resizeConsole()
{
    COORD coord;
    SMALL_RECT rect;
    HWND console = GetConsoleWindow();
    coord.X = 1920;
    coord.Y = 1080;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = 1919;
    rect.Bottom = 1079;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);
    ShowWindow(console, SW_MAXIMIZE);
}

// Function to check valid role
bool checkRole(string Ro)
{
    if (Ro == "ADMIN" || Ro == "INVESTOR" || Ro == "SUPPLIER" || Ro == "EMPLOYEE" || Ro == "CUSTOMER")
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to view one's profile
void viewProfile(int &index, string &profile)
{
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Profile \u001b[32;1m>\u001b[0m");

    for (int i = 0; i < index; i++)
    {
        if (username[i] == profile)
        {
            gotoxy(70, 26);
            cout << ">>> Username: " << username[i];
            gotoxy(70, 28);
            cout << ">>> Password: " << password[i];
            gotoxy(70, 30);
            cout << ">>> Role: " << role[i];
        }
    }

    pressKey();
}

// Function for Sign up & Sign In Options menu
string signMenu()
{
    string option = "0";
    int x = 59, y = 20;
    header();
    signHeader();
    cout << endl;
    cursorShow();
    gotoxy(x, y = y + 2);
    cout << "1. Sign Up: " << endl;
    gotoxy(x, y = y + 2);
    cout << "2. Sign In: " << endl;
    gotoxy(x, y = y + 2);
    cout << "3. Exit" << endl;
    gotoxy(x, y = y + 2);
    cout << "Your Option: ";
    getline(cin, option);

    return option;
}

// Function to check validity of signUp
bool signUp(string Name, string Pass, string Ro, string username[], string password[], string role[], int index)
{
    bool result = true;
    for (int i = 0; i <= index; i++)
    {
        if (Name == username[i])
        {
            result = false;
            break;
        }
    }
    return result;
}

// Functions to check the user by sign In
string signIn(int &index, string &profile)
{
    string userName1 = "";
    string password1 = "";

    cursorHide();
    head();
    signHeader();
    cursorShow();

    gotoxy(x6 + 6, y2 + 2);
    cout << ">>> Enter Username: ";
    getline(cin, userName1);

    gotoxy(x6 + 6, y2 + 6);
    cout << ">>> Enter Password: ";
    getline(cin, password1);

    profile = userName1;

    for (int i = 0; i < index; i++)
    {

        if (userName1 == username[i] && password1 == password[i] && role[i] == "ADMIN")
        {
            return "admin";
        }
        else if (userName1 == username[i] && password1 == password[i] && role[i] == "INVESTOR")
        {
            return "investor";
        }
        else if (userName1 == username[i] && password1 == password[i] && role[i] == "SUPPLIER")
        {
            return "supplier";
        }
        else if (userName1 == username[i] && password1 == password[i] && role[i] == "EMPLOYEE")
        {
            return "employee";
        }
        else if (userName1 == username[i] && password1 == password[i] && role[i] == "CUSTOMER")
        {
            return "customer";
        }
    }

    return "invalid";
}

// Menu's

int adminMenu()
{
    string strOption = "";
    int x = 65, y = 18;

    gotoxy(x, y = y + 6);
    cout << ">>> 1.  Add Employee" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 2.  Remove Employee" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 3.  View All Empoyee's: " << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 4.  Add Item" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 5.  Remove Item" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 6.  Add Or Update Items" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 7.  View Items" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 8.  Update Salary" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 9.  Add Investor" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 10. Give Discount" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 11. View Feedback" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 12. Log Out" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 13. Exit" << endl;
    gotoxy(x, y = y + 2);
    cout << "Your Option: ";
    getline(cin, strOption);

    if (containsOnlyIntegers(strOption))
    {
        int option = stoi(strOption);
        return option;
    }
    else
    {
        return -1;
    }
}

int investorMenu()
{
    string strOption = "";
    int x = 65, y = 18;

    gotoxy(x, y = y + 6);
    cout << ">>> 1. View Profile" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 2. Change password" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 3. View Employee Profile" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 4. View Revenue" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 5. View Supplier Profile" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 6. View Items" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 7. Add Item" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 8. Remove Item" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 9. Log Out" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 10. Exit" << endl;
    gotoxy(x, y = y + 2);
    cout << "Your Option: ";
    getline(cin, strOption);

    if (containsOnlyIntegers(strOption))
    {
        int option = stoi(strOption);
        return option;
    }
    else
    {
        return -1;
    }
}

int supplierMenu()
{
    string strOption = "";
    int x = 65, y = 18;

    gotoxy(x, y = y + 6);
    cout << ">>> 1. View Profile" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 2. Offer Products" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 3. Offer Discount On Products" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 4. Check Receiving" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 5. Withdraw Balance" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 6. View Items" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 7. Log Out" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 8. Exit" << endl;
    gotoxy(x, y = y + 2);
    cout << "Your Option: ";
    getline(cin, strOption);

    if (containsOnlyIntegers(strOption))
    {
        int option = stoi(strOption);
        return option;
    }
    else
    {
        return -1;
    }
}

int employeeMenu()
{
    string strOption = "";
    int x = 65, y = 18;

    gotoxy(x, y = y + 6);
    cout << ">>> 1. View Profile" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 2. Change Password" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 3. View Inventory" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 4. Move Items From Inventory To For Sale" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 5. View Items" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 6. Add Items" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 7. Remove Items" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 8. Update Items" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 9. Log Out" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 10. Exit" << endl;
    gotoxy(x, y = y + 2);
    cout << "Your Option: ";
    getline(cin, strOption);

    if (containsOnlyIntegers(strOption))
    {
        int option = stoi(strOption);
        return option;
    }
    else
    {
        return -1;
    }
}

int customerMenu()
{
    string strOption = "";
    int x = 65, y = 18;

    gotoxy(x, y = y + 6);
    cout << ">>> 1. View Profile" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 2. Change Password" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 3. View Items" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 4. Add Items To Cart" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 5. View Bill" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 6. Give Feedback" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 7. Log Out" << endl;
    gotoxy(x, y = y + 1);
    cout << ">>> 8. Exit" << endl;
    gotoxy(x, y = y + 2);
    cout << "Your Option: ";
    getline(cin, strOption);

    if (containsOnlyIntegers(strOption))
    {
        int option = stoi(strOption);
        return option;
    }
    else
    {
        return -1;
    }
}

// Functions to view invalid option //

void invalidUser()
{
    cout << "\e[0;31mInvalid Username or Password...\e[0m";
    Sleep(1000);
}

void invalidOption()
{
    cout << "\e[0;31mInvalid Entry...\e[0m";
    Sleep(500);
}

void invalidCredential()
{
    cout << "\e[0;31mInvalid Credentials...\e[0m";
    Sleep(500);
}

void invalidSerialNo()
{
    cout << "\e[0;31mWrong Serial Number...\e[0m";
    Sleep(500);
}

void pressKey()
{
    cout << "\n\nPress any key to continue...";
    getch();
}

// Admin Functions //

// Function to add an employee to the system
int addEmp(int &index, int &addEmpIndex)
{
    int x = 60;
    string Name, Pass;
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Add Employee \u001b[32;1m>\u001b[0m");

    gotoxy(x, 25);
    cout << ">>> Enter the Username of the employee you want to add: ";
    cin >> Name;
    gotoxy(x, 26);
    cout << ">>> Enter password of the employee you want to add: ";
    cin >> Pass;

    bool answer = signUp(Name, Pass, "EMPLOYEE", username, password, role, index);

    if (answer == true)
    {
        username[index] = Name;
        password[index] = Pass;
        role[index] = "EMPLOYEE";

        // Add the following lines to input the salary
        gotoxy(x, 27);
        cout << ">>> Enter the salary of the employee: ";
        cin >> addEmployeeSalary[index];
        index++;

        cout << "\n\t\t\t\t\t\t\t\t\e[0;92mEmployee added successfully...\e[0m";
        Sleep(1000);
    }
    else
    {
        gotoxy(x, 28);
        invalidUser();
    }
}

// Function to remove an employee from the system
int removeEmp(int &index, int &viewSerial, int &employeeSerial)
{
    string strSerial = "";

    viewEmployees(index, viewSerial, employeeSerial);

    cout << "\n\n\n\t\t\t\t\t>>> Enter the serial No. of Employee: ";
    cin >> strSerial;

    if (containsOnlyIntegers(strSerial))
    {
        int serial = stoi(strSerial);

        if (serial > 0 && serial <= employeeSerial)
        {
            int employeeIndex = -1; // Variable to store the index of the employee to be removed
            int count = 0;          // Variable to count employees with the correct role

            // Find the index of the employee with the specified serial number and role
            for (int i = 0; i < index; i++)
            {
                if (role[i] == "EMPLOYEE")
                {
                    count++;
                    if (count == serial)
                    {
                        employeeIndex = i;
                        break;
                    }
                }
            }

            if (employeeIndex != -1)
            {
                // Shift the elements to remove the employee
                for (int i = employeeIndex; i < index - 2; i++)
                {
                    username[i] = username[i + 1];
                    password[i] = password[i + 1];
                    role[i] = role[i + 1];
                    addEmployeeSalary[i] = addEmployeeSalary[i + 1];
                }

                index--;

                cout << "\n\t\t\t\t\t\e[0;92mEmployee removed successfully...\e[0m";
                Sleep(1000);
            }
            else
            {
                invalidSerialNo();
            }
        }
        else
        {
            invalidSerialNo();
        }
    }
    else
    {
        invalidCredential();
    }
}

// Function to view employees in the system
int viewEmployees(int &index, int &viewSerial, int &employeeSerial)
{
    int y = 24;
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Employee's \u001b[32;1m>\u001b[0m");

    gotoxy(40, 24);
    cout << "Sr.#";
    gotoxy(80, 24);
    cout << "Username";
    gotoxy(120, 24);
    cout << "Password";

    for (int i = 0; i < index; i++)
    {
        if (role[i] == "EMPLOYEE")
        {
            gotoxy(40, y + 2);
            cout << viewSerial;
            gotoxy(80, y + 2);
            cout << username[i];
            gotoxy(120, y + 2);
            cout << password[i];
            viewSerial++;

            y += 2;
        }
    }
    employeeSerial = viewSerial;
    viewSerial = 1;

    pressKey();
}

// Function to add an item to the system
int addItem(int &itemIndex)
{
    int x = 60;
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Add Items \u001b[32;1m>\u001b[0m");

    gotoxy(0, 25);
    cout << "\t\t\t\t\t>>> Enter the name of the item: ";
    cin >> itemName[itemIndex];
    cout << "\t\t\t\t\t>>> Enter the price of the item: ";
    cin >> itemPrice[itemIndex];
    cout << "\t\t\t\t\t>>> Enter the quantity of the item: ";
    cin >> itemQuantity[itemIndex];

    if (containsOnlyIntegers(itemPrice[itemIndex]) && containsOnlyIntegers(itemQuantity[itemIndex]))
    {
        itemIndex++;
        cout << "\t\t\t\t\t\e[0;92mItem Entered successfully...\e[0m";
        Sleep(1000);
    }
    else
    {
        gotoxy(x, 29);
        invalidCredential();
    }
}

// Function to remove an item from the system
int removeItem(int &itemIndex)
{
    string strSr = "";

    viewItems(itemIndex);
    cout << "\n\n\n\t\t\t\t\t>>> Enter the Serial Number of the item you want to delete: ";
    cin >> strSr;

    if (containsOnlyIntegers(strSr))
    {
        int sr = stoi(strSr);
        if (sr <= itemIndex && sr > 0)
        {
            for (int i = 0; i < itemIndex - 1; i++)
            {
                if (sr - 1 == i)
                {
                    itemName[i] = itemName[i + 1];
                    itemPrice[i] = itemPrice[i + 1];
                    itemQuantity[i] = itemQuantity[i + 1];
                }
            }
            itemIndex--;

            cout << "\n\t\t\t\t\t\e[0;92mItem Removed Successfully...\e[0m";
            Sleep(500);
        }
        else
        {
            invalidSerialNo();
        }
    }
    else
    {
        invalidCredential();
    }
}

// Function to update information about an item in the system
int updateItem(int &index, int &itemIndex)
{
    string sr, price, quantity, name;

    viewItems(itemIndex);

    cout << "\n\t\t\t\t\t>>> Enter the Serial Number of the item you want to update: ";
    cin >> sr;

    cout << "\n\t\t\t\t\t>>> Enter New Name: ";
    cin >> name;
    cout << "\n\t\t\t\t\t>>> Enter New Price: ";
    cin >> price;
    cout << "\n\t\t\t\t\t>>> Enter New Quantity: ";
    cin >> quantity;

    if (containsOnlyIntegers(sr) && containsOnlyIntegers(price) && containsOnlyIntegers(quantity))
    {
        int intSr = stoi(sr), intPrice = stoi(price), intQuantity = stoi(quantity);

        if (intSr <= itemIndex && intSr > 0)
        {
            for (int i = 0; i < itemIndex; i++)
            {
                if (intSr - 1 == i)
                {
                    itemName[i] = name;
                    itemPrice[i] = price;
                    itemQuantity[i] = quantity;

                    cout << "\e[0;92mItem Updated Successfully...\e[0m\n";
                    Sleep(500);
                }
            }
        }
        else
        {
            invalidSerialNo();
        }
    }
    else
    {
        invalidCredential();
    }
}

// Function to view items in the system
int viewItems(int &itemIndex)
{
    int y = 22;
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Items \u001b[32;1m>\u001b[0m");

    gotoxy(30, 22);
    cout << "Sr.#";
    gotoxy(60, 22);
    cout << "Name";
    gotoxy(90, 22);
    cout << "Price";
    gotoxy(120, 22);
    cout << "Quantity";
    for (int i = 0; i < itemIndex; i++)
    {
        gotoxy(30, y + 2);
        cout << i + 1;
        gotoxy(60, y + 2);
        cout << itemName[i];
        gotoxy(90, y + 2);
        cout << itemPrice[i];
        gotoxy(120, y + 2);
        cout << itemQuantity[i];

        y += 2;
    }

    pressKey();
}

// Function to add or update the salary of an employee
int addOrUpdateSalary(int &index, int &viewSerial, int &employeeSerial)
{
    string name = "", salary = "";

    viewEmployees(index, viewSerial, employeeSerial);

    cout << "\n\t\t\t\t\t>>> Enter the name of the employee: ";
    cin >> name;
    cout << "\n\t\t\t\t\t>>> Enter the amount of salary: ";
    cin >> salary;

    if (containsOnlyAlphabets(name))
    {
        if (containsOnlyIntegers(salary))
        {
            for (int i = 0; i < index; i++)
            {
                if (name == username[i])
                {
                    addEmployeeSalary[i] = salary;

                    cout << "\e[0;92mSalary Updated Successfully...\e[0m\n";
                    Sleep(500);
                }
            }
        }
        else
        {
            invalidCredential();
        }
    }
    else
    {
        invalidCredential();
    }
}

// Function to add an investor to the system
int addInvestor(int &index)
{
    string name, pass, passKey;

    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Add Investor \u001b[32;1m>\u001b[0m");

    cout << "\t\t\t\t\t>>> Enter pass Key: ";
    cin >> passKey;

    if (passKey == secretKey)
    {
        cout << "\n\t\t\t\t\t>>> Enter the username of the investor: ";
        cin >> name;
        cout << "\t\t\t\t\t>>> Enter the Password of the investor: ";
        cin >> pass;

        bool answer = signUp(name, pass, "INVESTOR", username, password, role, index);

        if (answer == true)
        {
            username[index] = name;
            password[index] = pass;
            index++;
            cout << "\t\t\t\t\t\e[0;92mInvestor is successfully added...\e[0m";
            Sleep(1000);
        }
        else
        {
            invalidUser();
        }
    }
    else
    {
        cout << "\n\t\t\t\t\tInvalid Pass Key...";
        Sleep(500);
    }
}

// Function to apply a discount to an item
int discount(int &itemIndex)
{
    string strSr = "";
    string strDiscount = "";

    viewItems(itemIndex);
    cout << "\n\t\t\t\t\t>>> Enter the serial No. of the product: ";
    cin >> strSr;
    cout << "\t\t\t\t\t>>> Enter the percentage(%) of discount: ";
    cin >> strDiscount;

    if (containsOnlyIntegers(strSr) && containsOnlyIntegers(strDiscount))
    {
        int sr = stoi(strSr), discount = stoi(strDiscount);

        if (sr <= itemIndex && sr > 0)
        {
            for (int i = 0; i < itemIndex; i++)
            {
                // convert string itemPrice to integer
                int itemPrice1 = stoi(itemPrice[i]);
                if (sr - 1 == i)
                {
                    itemPrice1 = itemPrice1 - (itemPrice1 * discount) / 100;
                    // Convert item price again to string and give value to itemPrice array
                    itemPrice[i] = to_string(itemPrice1);
                }
            }
        }
        else
        {
            invalidSerialNo();
        }
    }
    else
    {
        invalidCredential();
    }
}

// Function to view feedback statistics
void viewFeedback()
{
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Feedback \u001b[32;1m>\u001b[0m");

    cout << "\n\t\t\t\t\t\t>>> Excellent Experience: " << excellent;
    cout << "\n\t\t\t\t\t\t>>> Good Experience: " << good;
    cout << "\n\t\t\t\t\t\t>>> Bad Experience: " << bad;
    cout << "\n\t\t\t\t\t\t>>> Worst Experience: " << worst << endl;

    pressKey();
}

// Function to logout
void logout()
{
    head();

    cout << "\n\u001b[1m\u001b[36;1m\u001b[1mLogging Out...\u001b[0m" << endl;
    for (int i = 0; i < 100; i++)
    {
        Sleep(10);
        cout << "\033[1000D" << i + 1 << "%" << flush;
    }
    cout << endl;
}

// Investor Functions //

// Function to change the password
int changePass(int &index, string &profile)
{
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Change Password \u001b[32;1m>\u001b[0m");

    for (int i = 0; i < index; i++)
    {
        if (username[i] == profile)
        {
            gotoxy(75, 24);
            cout << ">>> Old password is: " << password[i];

            gotoxy(75, 25);
            cout << ">>> Enter New Password: ";
            cin >> password[i];

            gotoxy(75, 27);
            cout << "\e[0;92mPassword changed successfully...\e[0m";
            Sleep(1000);
        }
    }
}

// Function to view the income or revenue
void viewRevenue(int &profit)
{
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m View Revenue \u001b[32;1m>\u001b[0m");

    gotoxy(75, 30);
    cout << ">>> Revenue is: " << profit;

    pressKey();
}

// Function to view all suppliers profiles
void SuppliersProfiles(int &index, int &viewSerial)
{
    int y = 24;
    subMenuHeader("\u001b[1m\u001b[32;1m<\u001b[0m\u001b[1m Suppliers Profiles \u001b[32;1m>\u001b[0m");

    gotoxy(40, 24);
    cout << "Sr.#";
    gotoxy(80, 24);
    cout << "Username";
    gotoxy(120, 24);
    cout << "Password";

    for (int i = 0; i <= index; i++)
    {
        if (role[i] == "SUPPLIER")
        {
            gotoxy(40, y + 2);
            cout << viewSerial;
            gotoxy(80, y + 2);
            cout << username[i];
            gotoxy(120, y + 2);
            cout << password[i];
            viewSerial++;

            y += 2;
        }
    }

    viewSerial = 1;
    pressKey();
}

// Supplier's Functions //

// Function to add item in the inventory by the supplier
int enterProducts(int &inventoryIndex)
{
    string price = "", quantity = "";

    subMenuHeader("\u001b[1m\u001b[32;1m<\u001b[0m\u001b[1m Add Products \u001b[32;1m>\u001b[0m");

    cout << "\n";
    cout << "\t\t\t\t\t>>> Enter the Product name: ";
    cin >> inventoryProduct[inventoryIndex];
    cout << "\t\t\t\t\t>>> Enter the product price: ";
    cin >> price;
    cout << "\t\t\t\t\t>>> Enter the product quantity: ";
    cin >> quantity;

    if (containsOnlyIntegers(price) && containsOnlyIntegers(quantity))
    {
        inventoryPrice[inventoryIndex] = price;
        inventoryQuantity[inventoryIndex] = quantity;
        inventoryIndex++;

        cout << "\n\n";
        cout << "\e[0;92mProduct Added Successfully...\e[0m";
        Sleep(500);
    }
    else
    {
        invalidCredential();
    }
}

// Function to view the inventory
int viewInventory(int &inventoryIndex)
{
    int y = 24;
    subMenuHeader("\u001b[1m\u001b[32;1m<\u001b[0m\u001b[1m Inventory \u001b[32;1m>\u001b[0m");

    gotoxy(30, 24);
    cout << "Sr No.";
    gotoxy(60, 24);
    cout << "Name";
    gotoxy(90, 24);
    cout << "Price";
    gotoxy(120, 24);
    cout << "Quantity";

    for (int i = 0; i < inventoryIndex; i++)
    {
        gotoxy(30, y + 2);
        cout << i + 1;
        gotoxy(60, y + 2);
        cout << inventoryProduct[i];
        gotoxy(90, y + 2);
        cout << inventoryPrice[i];
        gotoxy(120, y + 2);
        cout << inventoryQuantity[i];

        y += 2;
    }

    pressKey();
}

// Function to give discount on inventory products by supplier
int offerDiscount(int &inventoryIndex)
{
    string strSr = "", strDiscount = "";

    viewInventory(inventoryIndex);
    cout << "\n";
    cout << "\t\t\t\t\t>>> Enter the serial Number of item for discount: ";
    cin >> strSr;
    cout << "\t\t\t\t\t>>> Enter the percentage(%) of discount: ";
    cin >> strDiscount;

    if (containsOnlyIntegers(strSr) && containsOnlyIntegers(strDiscount))
    {
        int sr = stoi(strSr), discount = stoi(strDiscount);
        if (sr > 0 && sr <= inventoryIndex + 1)
        {
            for (int i = 0; i < inventoryIndex; i++)
            {
                int price = stoi(inventoryPrice[i]);
                if (sr - 1 == i)
                {
                    inventoryPrice[i] = to_string(price - (price * discount) / 100);
                }
            }
        }
        else
        {
            invalidSerialNo();
        }
    }
    else
    {
        invalidCredential();
    }
}

// Function for supplier to check its total sale
int checkReceiving(int &inventoryIndex, int &balance)
{
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Your Receiving \u001b[32;1m>\u001b[0m");

    gotoxy(60, 25);
    cout << ">>> The amount of products you sold: " << inventoryIndex;

    for (int i = 0; i < inventoryIndex; i++)
    {
        balance += stoi(inventoryPrice[i]);
    }

    gotoxy(60, 27);
    cout << ">>> Your balance is: " << balance << " Rupee";
    pressKey();
}

// Function for suppier to withdraw its income
int withDrawBalance(int &balance)
{
    string strBalanceWithdraw;
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Withdraw Balance \u001b[32;1m>\u001b[0m");

    cout << "\n\t\t\t\t\t>>> Your balance is: " << balance << " Rupee" << endl;
    cout << "\t\t\t\t\t>>> Enter the amount you want to withdraw: ";
    cin >> strBalanceWithdraw;

    if (containsOnlyIntegers(strBalanceWithdraw))
    {
        int balanceWithdraw = stoi(strBalanceWithdraw);
        if (balanceWithdraw <= balance)
        {
            balance = balance - balanceWithdraw;

            cout << "\t\t\t\t\t\e[0;92mBalance withdraw successfully...\e[0m";
            Sleep(500);

            cout << "\n\n\t\t\t\t\tNew balance is: " << balance << " Rupee";

            pressKey();
        }
        else
        {
            invalidOption();
        }
    }
    else
    {
        invalidCredential();
    }
}

// Employee Functions //

// Function for employee to see its profile
void viewEmployeeProfile(int &index, string &profile)
{
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Your Profile \u001b[32;1m>\u001b[0m");

    for (int i = 0; i < index; i++)
    {
        if (username[i] == profile)
        {
            head();
            cout << "Username:\t\t" << username[i] << "\nPassword:\t\t" << password[i] << "\nRole:\t\t" << role[i] << "\nSalary:\t\t" << addEmployeeSalary[i];
            break;
        }
    }

    pressKey();
}

// Function for employee to move the items from inventory to the place where customer can see and buy them
void inventoryToSale(int &index, int &inventoryIndex, int &profit, int &itemIndex)
{
    string strSr = "", strPrice = "";
    viewInventory(inventoryIndex);

    cout << "\n\n\t\t\t\t\t>>> Enter the Serial No. Of Product: ";
    cin >> strSr;

    cout << "\n\t\t\t\t\t>>> Enter New Price: ";
    cin >> strPrice;

    if (containsOnlyIntegers(strSr) && containsOnlyIntegers(strPrice))
    {
        int sr, price;
        try
        {
            int sr = stoi(strSr);
            int price = stoi(strPrice);

            if (sr < inventoryIndex + 1 && sr > 0)
            {
                for (int i = 0; i < inventoryIndex; i++)
                {
                    if (sr - 1 == i)
                    {
                        // To move product to items list
                        itemName[i] = inventoryProduct[i];
                        itemPrice[i] = inventoryPrice[i];
                        itemQuantity[i] = inventoryQuantity[i];
                        itemIndex++;

                        // To delete current product from inventory
                        for (int j = i; j < inventoryIndex; j++)
                        {
                            inventoryProduct[j] = inventoryProduct[j + 1];
                            inventoryPrice[j] = inventoryPrice[j + 1];
                            inventoryQuantity[j] = inventoryQuantity[j + 1];
                        }
                        inventoryIndex--;

                        int newInventoryPrice = stoi(inventoryPrice[i]);

                        profit += (newInventoryPrice - price);
                        break;
                    }
                }
            }
            else
            {
                invalidCredential();
            }
        }
        catch (const std::invalid_argument &e)
        {
            // Handle the exception, perhaps print an error message
            invalidCredential();
            // Optionally, you can return from the function or take appropriate action.
            return;
        }
    }
    else
    {
        invalidCredential();
    }
}

// Customer Functions

// Function for customer to see its cart
int itemsToCart(int &itemIndex, int &cartIndex)
{
    string strSr = "", strQuantity = "";
    viewItems(itemIndex);

    cout << "\n\t\t\t\t\t>>> Enter the serial No. of item you want to add: ";
    cin >> strSr;
    cout << "\t\t\t\t\t>>> Enter the quanity: ";
    cin >> strQuantity;

    if (containsOnlyIntegers(strSr) && containsOnlyIntegers(strQuantity))
    {
        // Convert credentials to integers for calculations
        int sr = stoi(strSr), quantity = stoi(strQuantity);
        for (int i = 0; i < itemIndex; i++)
        {
            int itemQ = stoi(itemQuantity[i]);
            if (sr - 1 == i)
            {
                if (quantity <= itemQ)
                {
                    cartName[cartIndex] = itemName[i];
                    cartPrice[cartIndex] = itemPrice[i];
                    cartQuantity[cartIndex] = quantity;
                    cartIndex++;
                    itemName[i] = itemName[i + 1];
                    itemPrice[i] = itemPrice[i + 1];
                    itemQuantity[i] = to_string(itemQ - quantity);
                    itemIndex--;
                }
                else
                {
                    invalidCredential();
                    break;
                }
            }
        }
    }
    else
    {
        invalidCredential();
    }
}

// Function for customer to see its bill
int viewBill(int &cartIndex)
{
    int y = 10;

    gotoxy(75, 5);
    cout << "< Bill >";
    gotoxy(40, 10);
    cout << "Product Name";
    gotoxy(80, 10);
    cout << "Product Price";
    gotoxy(120, 10);
    cout << "Product Quantity";

    for (int i = 0; i < cartIndex; i++)
    {
        gotoxy(40, y + 2);
        cout << cartName[i];
        gotoxy(80, y + 2);
        cout << cartPrice[i];
        gotoxy(120, y + 2);
        cout << cartQuantity[i];

        y += 2;
    }

    pressKey();
}

// Function for cusotmer to give feedback
int giveFeedback()
{
    subMenuHeader("\u001b[32;1m<\u001b[0m\u001b[1m Your Feedback \u001b[32;1m>\u001b[0m");

    string strOption = "";
    cout << "\n\t\t\t\t\t>>> How was your experience:\n";
    cout << "\t\t\t\t\t1. Excellent :>\n\t\t\t\t\t2. Good :)\n\t\t\t\t\t3. Bad :/\n\t\t\t\t\t4. Worst :(\n\n";
    cout << "\t\t\t\t\tYour Option: ";
    cin >> strOption;

    if (containsOnlyIntegers(strOption))
    {
        int option = stoi(strOption);

        if (option > 0 && option < 5)
        {
            switch (option)
            {
            case 1:
                excellent++;
                break;
            case 2:
                good++;
                break;
            case 3:
                bad++;
                break;
            case 4:
                worst++;
                break;
            default:
                option = 0;
                break;
            }
        }
        else
        {
            invalidOption();
        }
    }
    else
    {
        invalidCredential();
    }
}

// Validations
bool containsOnlyAlphabets(string word) // It validates if the required input are alphabets
{
    bool result = false;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int asciiCode = word[i];

        if (asciiCode >= 65 && asciiCode <= 122)
        {
            result = true;
        }
    }

    return result;
}

bool containsOnlyIntegers(string integer) // It validates if the required input are integers
{
    bool result = false;

    for (int i = 0; integer[i] != '\0'; i++)
    {
        int asciiCode = integer[i];

        if (asciiCode >= 48 && asciiCode <= 57)
        {
            result = true;
        }
    }

    return result;
}
