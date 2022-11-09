#include "collection.h"

Collection::Collection()
{

}
vector<string> Collection::getMovieVector()
{
    return movies;
}

string Collection::getMovie(long pos)
{
    int totalSize = movies.size()/4;
    if (pos < 1 || pos > totalSize)
    {
        string error = "error";
        return error;
    }
    else
        return movies[(pos - 1) * 4];
}

void Collection::setAuthorInfo(string authorName, long pos)
{
    movies[(((pos - 1) * 4) + 1)] = authorName;
}

void Collection::setYearInfo(string yearName, long pos)
{
    movies[(((pos - 1) * 4) + 2)] = yearName;
}

void Collection::setGenreInfo(string genreName, long pos)
{
    movies[(((pos - 1) * 4) + 3)] = genreName;
}

void Collection::setMovie(string movieName) //теперь работает
{
    string noInfo = "No info";
    movies.push_back(movieName);
    for(int i = 0; i < 3; i++)
    movies.push_back(noInfo);
}

int Collection::numberOfMovies()
{
    return movies.size()/4;
}

void Collection::listMovies()
{
    for(int i = 0; i < (movies.size()/4); i++)
    {
        cout << i + 1 << ". " << movies[i*4] << endl;
    }
}

string Collection::delMovie(long pos)
{
    string title = getMovie(pos);
    if (title != "error")
    {
    string elem = getMovie(pos);
    for(int i = -1; i < 3; i++)
    movies.erase(movies.begin() + (pos + i) * 4);
    return elem;
    }
    else
    return title;
}
void Collection::exportExtensionCollection(string fileName)
{
    ofstream file;
    file.open (fileName + ".txt");
    string temp = "";
    for(long i = 0; i < movies.size() - 1; i++)
        file << movies[i] << endl;
    file << movies[movies.size() - 1];
    file.close();
}

void Collection::exportNoExtensionCollection(string fileName)
{
    ofstream file;
    file.open (fileName);
    string temp = "";
    for(long i = 0; i < movies.size() - 1; i++)
        file << movies[i] << endl;
    file << movies[movies.size() - 1];
    file.close();
}

string Collection::importExtensionCollection(string fileName)
{
      string movie;
      ifstream file (fileName + ".txt");
      if (file.is_open())
      {
        movies.clear();
        while ( getline (file, movie) )
        {
          movies.push_back(movie);
        }
        file.close();
        return "File loaded.";
      }
      else
        return "Unable to open file.";

}

string Collection::importNoExtensionCollection(string fileName)
{
      string movie;
      ifstream file (fileName);
      if (file.is_open())
      {
        movies.clear();
        while ( getline (file, movie) )
        {
          movies.push_back(movie);
        }
        file.close();
        return "File loaded.";
      }
      else
        return "Unable to open file.";

}

void Collection::replace(long pos)
{
    movies[pos] = "No info";
}

void Collection::AdditionalInfo()
{
    system ("CLS");
    listMovies();
    cout << endl <<"Which movie do you pick? > ";
    long pos;
    cin >> pos;
    char menu;
    do
    {
        system ("CLS");
        puts ("1. Look additional info");
        puts ("2. Add Author");
        puts ("3. Add Year");
        puts ("4. Add Genre");
        puts ("5. Clear info");
        puts ("6. Return to main menu");
        cout << endl << "select menu item: ";
        menu = getchar();
        cout << endl;
        switch (menu)
        {
        case '1': //Check info
        {
            for (int i = 0; i < 4; i++){
                cout << movies[((pos -1) * 4) + i] << endl;}
            cout << endl;
            system ("PAUSE");
            break;
        }
        case '2': //Add Author
        {
            cout << "enter movie author: ";
            string title = "No info";
            cin >> title;
            setAuthorInfo(title, pos);
            cout << endl << "Author \"" << title << "\" has added to movie." << endl << endl;
            system ("PAUSE");
            break;
        }
        case '3': //Add Year
        {
            cout << "enter movie year: ";
            string title = "No info";
            cin >> title;
            setYearInfo(title, pos);
            cout << endl << "Year \"" << title << "\" has added to movie." << endl << endl;
            system ("PAUSE");
            break;
        }
        case '4': //Add Genre
        {
            cout << "enter movie genre: ";
            string title = "No info";
            cin >> title;
            setGenreInfo(title, pos);
            cout << endl << "Genre \"" << title << "\" has added to movie." << endl << endl;
            system ("PAUSE");
            break;
        }
        case '5': //Clear Info
        {
            cout << "Which info you want to delete? (author/year/genre/all) > ";
            string title;
            cin >> title;
            string result = "wrong command";
            if (title == "author")
            {
                int i = 1;
                replace(((pos - 1) * 4) + i);
                result = "author";
            }
            if (title == "year")
            {
                int i = 2;
                replace(((pos - 1) * 4) + i);
                result = "year";
            }
            if (title == "genre")
            {
                int i = 3;
                replace(((pos - 1) * 4) + i);
                result = "genre";
            }
            if (title == "all")
            {
                for(int i = 1; i < 4; i++)
                    replace(((pos - 1) * 4) + i);
                result = "All info";
            }
            if(result != "wrong command")
            {
            cout << endl << result << " has deleted from movie." << endl << endl;
            system ("PAUSE");
            break;
            }
            else
            {
                cout << endl << result << endl << endl;
                break;
            }
        }
        }
    } while(menu != '6');
}

