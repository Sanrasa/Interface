#include <iostream>
#include "collection.h"
#include "genre.h"

using namespace std;

int main()
{
    char menu;
    Collection myCollection;
        do {
            system ("CLS");
            puts ("1. Add movie");
            puts ("2. Get movie");
            puts ("3. Select movie");
            puts ("4. List of movies");
            puts ("5. Number of movies");
            puts ("6. Remove movie");
            puts ("7. Export collection");
            puts ("8. Import collection");
            puts ("9. Inheritace");
            puts ("0. Exit");
            cout << endl << "select menu item: ";
            menu = getchar();
            cout << endl;
            switch (menu)
            {
            case '1': //Add movie
            {
                cout << "enter movie title: ";
                string title;
                cin >> title;
                myCollection.setMovie(title);
                cout << endl << "Movie \"" << title << "\" has added to collection." << endl << endl;
                system ("PAUSE");
                break;
            }
            case '2': //Get movie
            {
                long pos;
                cout << "Inter position of the movie: ";
                cin >> pos;
                string title = myCollection.getMovie(pos);
                if (title != "error")
                    cout << endl << "Movie title is \"" << title << "\"" << endl << endl;
                else
                    cout << endl << "That number not exist in collection" << endl << endl;
                system ("PAUSE");
                break;
            }
            case '3': //select movie
            {
                myCollection.AdditionalInfo();
                break;
            }
            case '4': //List of movies
            {
                system ("CLS");
                myCollection.listMovies();
                cout << endl;
                system ("PAUSE");
                break;
            }
            case '5': //Number of movies
            {
                cout << "Collection have " << myCollection.numberOfMovies() << " movies." << endl << endl;
                system ("PAUSE");
                break;
            }
            case '6': //Remove movie
            {
                long pos;
                cout << "Type position of movie which you want to delete: ";
                cin >> pos;
                string title = myCollection.delMovie(pos);
                if (title != "error")
                    cout << endl << "Movie \"" << title << "\"" << " successfuly deleted from collection." << endl << endl;
                else
                    cout << endl << "That number not exist in collection" << endl << endl;
                system ("PAUSE");
                break;
            }
            case '7': //export collection
            {
                string fileName;
                char answer = 'g';
                cout << endl << "Do you need extension for your collection? (y/n) > ";
                cin >> answer;
                if (answer == 'y' or answer == 'n')
                    if (answer == 'y')
                    {
                        cout << endl << "How to name your file?" << endl << endl << ">";
                        cin >> fileName;
                        myCollection.exportExtensionCollection(fileName);
                        cout << endl << "File successfuly created." << endl << endl;
                    } else
                    {
                        cout << endl << "How to name your file?" << endl << endl << ">";
                        cin >> fileName;
                        myCollection.exportNoExtensionCollection(fileName);
                        cout << endl << "File successfuly created." << endl << endl;
                    }
                else
                    cout << endl << "Wrong command!" << endl << endl;
                system("PAUSE");
                break;
            }
            case '8': //import collection
            {
                string fileName;
                string status;
                char answer = 'g';
                cout << endl << "Does your collection have an extension? (y/n) > ";
                cin >> answer;
                if (answer == 'y' or answer == 'n')
                    if (answer == 'y')
                    {
                        cout << endl << "What is the name of the file?" << endl << endl << ">";
                        cin >> fileName;
                        status = myCollection.importExtensionCollection(fileName);
                            if (status != "Unable to open file.")
                                cout << endl << "File successfuly loaded." << endl << endl;
                            else
                                cout << endl << status << endl << endl;
                    }
                    else
                    {
                        cout << endl << "What is the name of the file?" << endl << endl << ">";
                        cin >> fileName;
                        status = myCollection.importNoExtensionCollection(fileName);
                            if (status != "Unable to open file.")
                                cout << endl << "File successfuly loaded." << endl << endl;
                            else
                                cout << endl << status << endl << endl;
                    }
                else
                    cout << endl << "Wrong command!" << endl << endl;
                system ("PAUSE");
                break;
            }
            case '9': //Inheritance
            {
                Genre col;
                col.AdditionalInfo();
            }
            }
        } while (menu != '0'); //Exit

    return 0;
}
