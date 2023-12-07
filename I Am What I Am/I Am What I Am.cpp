// I Am What I Am.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

//Завдання 3

#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 10;

// Structure to represent a task
struct Task {
    string title;
    int priority;
    string description;
    string dueDate;
    string dueTime;
};

// Function to add a task to the list
void addTask(Task tasks[], int& taskCount) {
    if (taskCount < MAX_TASKS) {
        Task newTask;

        cout << "Enter the task title: ";
        cin >> newTask.title;

        cout << "Enter the task priority (integer): ";
        cin >> newTask.priority;

        cout << "Enter the task description: ";
        cin >> newTask.description;

        cout << "Enter the due date (format: YYYY-MM-DD): ";
        cin >> newTask.dueDate;

        cout << "Enter the due time (format: HH:MM): ";
        cin >> newTask.dueTime;

        tasks[taskCount++] = newTask;

        cout << "Task successfully added!\n";
    }
    else {
        cout << "Maximum number of tasks reached. Unable to add more.\n";
    }
}

// Function to display all tasks in the list
void displayTasks(const Task tasks[], int taskCount) {
    cout << "\nTask List:\n";

    for (int i = 0; i < taskCount; i++) {
        cout << "------------------------\n";
        cout << "Title: " << tasks[i].title << "\n";
        cout << "Priority: " << tasks[i].priority << "\n";
        cout << "Description: " << tasks[i].description << "\n";
        cout << "Due Date: " << tasks[i].dueDate << "\n";
        cout << "Due Time: " << tasks[i].dueTime << "\n";
    }

    cout << "------------------------\n";
}

// Function to delete a task by index
void deleteTask(Task tasks[], int& taskCount, int index) {
    if (index >= 0 && index < taskCount) {
        for (int i = index; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task successfully deleted!\n";
    }
    else {
        cout << "Invalid index. Task not deleted.\n";
    }
}

// Function to edit a task by index
void editTask(Task tasks[], int taskCount, int index) {
    if (index >= 0 && index < taskCount) {
        cout << "Enter the new title: ";
        cin >> tasks[index].title;

        cout << "Enter the new priority (integer): ";
        cin >> tasks[index].priority;

        cout << "Enter the new description: ";
        cin >> tasks[index].description;

        cout << "Enter the new due date (format: YYYY-MM-DD): ";
        cin >> tasks[index].dueDate;

        cout << "Enter the new due time (format: HH:MM): ";
        cin >> tasks[index].dueTime;

        cout << "Task successfully edited!\n";
    }
    else {
        cout << "Invalid index. Task not edited.\n";
    }
}

// Function to search for tasks by various criteria
void searchTasks(const Task tasks[], int taskCount) {
    cout << "\nSearch for tasks:\n";
    cout << "1. By title\n";
    cout << "2. By priority\n";
    cout << "3. By description\n";
    cout << "4. By due date\n";
    cout << "5. By due time\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        string searchTitle;
        cout << "Enter the title to search for: ";
        cin >> searchTitle;

        cout << "\nMatching tasks:\n";
        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].title == searchTitle) {
                cout << "------------------------\n";
                cout << "Title: " << tasks[i].title << "\n";
                cout << "Priority: " << tasks[i].priority << "\n";
                cout << "Description: " << tasks[i].description << "\n";
                cout << "Due Date: " << tasks[i].dueDate << "\n";
                cout << "Due Time: " << tasks[i].dueTime << "\n";
            }
        }
        break;
    }
    case 2: {
        int searchPriority;
        cout << "Enter the priority to search for: ";
        cin >> searchPriority;

        cout << "\nMatching tasks:\n";
        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].priority == searchPriority) {
                cout << "------------------------\n";
                cout << "Title: " << tasks[i].title << "\n";
                cout << "Priority: " << tasks[i].priority << "\n";
                cout << "Description: " << tasks[i].description << "\n";
                cout << "Due Date: " << tasks[i].dueDate << "\n";
                cout << "Due Time: " << tasks[i].dueTime << "\n";
            }
        }
        break;
    }
    case 3: {
        string searchDescription;
        cout << "Enter the description to search for: ";
        cin >> searchDescription;

        cout << "\nMatching tasks:\n";
        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].description == searchDescription) {
                cout << "------------------------\n";
                cout << "Title: " << tasks[i].title << "\n";
                cout << "Priority: " << tasks[i].priority << "\n";
                cout << "Description: " << tasks[i].description << "\n";
                cout << "Due Date: " << tasks[i].dueDate << "\n";
                cout << "Due Time: " << tasks[i].dueTime << "\n";
            }
        }
        break;
    }
    case 4: {
        string searchDueDate;
        cout << "Enter the due date to search for (format: YYYY-MM-DD): ";
        cin >> searchDueDate;

        cout << "\nMatching tasks:\n";
        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].dueDate == searchDueDate) {
                cout << "------------------------\n";
                cout << "Title: " << tasks[i].title << "\n";
                cout << "Priority: " << tasks[i].priority << "\n";
                cout << "Description: " << tasks[i].description << "\n";
                cout << "Due Date: " << tasks[i].dueDate << "\n";
                cout << "Due Time: " << tasks[i].dueTime << "\n";
            }
        }
        break;
    }
    case 5: {
        string searchDueTime;
        cout << "Enter the due time to search for (format: HH:MM): ";
        cin >> searchDueTime;

        cout << "\nMatching tasks:\n";
        for (int i = 0; i < taskCount; ++i) {
            if (tasks[i].dueTime == searchDueTime) {
                cout << "------------------------\n";
                cout << "Title: " << tasks[i].title << "\n";
                cout << "Priority: " << tasks[i].priority << "\n";
                cout << "Description: " << tasks[i].description << "\n";
                cout << "Due Date: " << tasks[i].dueDate << "\n";
                cout << "Due Time: " << tasks[i].dueTime << "\n";
            }
        }
        break;
    }
    default:
        cout << "Invalid choice. No tasks searched.\n";
    }
}

// Function to sort tasks by priority
void sortTasksByPriority(Task tasks[], int taskCount) {
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = 0; j < taskCount - i - 1; j++) {
            if (tasks[j].priority > tasks[j + 1].priority) {
                // Swap tasks
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    cout << "\nTasks sorted by priority:\n";
    displayTasks(tasks, taskCount);
}

// Function to sort tasks by due date and time
void sortTasksByDateTime(Task tasks[], int taskCount) {
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = 0; j < taskCount - i - 1; j++) {
            // Concatenate due date and time for comparison
            string dateTime1 = tasks[j].dueDate + " " + tasks[j].dueTime;
            string dateTime2 = tasks[j + 1].dueDate + " " + tasks[j + 1].dueTime;

            if (dateTime1 > dateTime2) {
                // Swap tasks
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    cout << "\nTasks sorted by due date and time:\n";
    displayTasks(tasks, taskCount);
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    char choice;

    do {
        cout << "Choose an action:\n";
        cout << "1. Add a task\n";
        cout << "2. Display task list\n";
        cout << "3. Edit a task\n";
        cout << "4. Delete a task\n";
        cout << "5. Search for tasks\n";
        cout << "6. Sort tasks by priority\n";
        cout << "7. Sort tasks by due date and time\n";
        cout << "8. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            addTask(tasks, taskCount);
            break;
        case '2':
            displayTasks(tasks, taskCount);
            break;
        case '3':
            int editIndex;
            cout << "Enter the index of the task you want to edit: ";
            cin >> editIndex;
            editTask(tasks, taskCount, editIndex);
            break;
        case '4':
            int deleteIndex;
            cout << "Enter the index of the task you want to delete: ";
            cin >> deleteIndex;
            deleteTask(tasks, taskCount, deleteIndex);
            break;
        case '5':
            searchTasks(tasks, taskCount);
            break;
        case '6':
            sortTasksByPriority(tasks, taskCount);
            break;
        case '7':
            sortTasksByDateTime(tasks, taskCount);
            break;
        case '8':
            cout << "Thank you for using the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '8');

    return 0;
}*/





#include <iostream>
#include <fstream>

using namespace std;

const int MAX_CHARACTERS = 10000;  // Maximum number of characters in lyrics

struct Song {
    string title;
    string author;
    string lyrics;
    int year;
};

void inputLyricsFromConsole(Song& song) {
    cout << "Введіть текст пісні (введення завершиться, коли ви введете слово 'END'):\n";
    string line;
    song.lyrics = "";

    char c;
    while (cin.get(c) && c != '\n') {
        if (c == 'E') {
            // Check for 'END'
            cin.get(c);
            if (c == 'N') {
                cin.get(c);
                if (c == 'D') {
                    break;  // 'END' encountered
                }
            }
        }
        song.lyrics += c;
    }
}

void inputLyricsFromFile(Song& song, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        char c;
        while (file.get(c)) {
            song.lyrics += c;
        }
        file.close();
    }
    else {
        cout << "Не вдалося відкрити файл.\n";
    }
}

void deleteSong(Song* songs, int& numOfSongs, const string& titleToDelete) {
    int indexToDelete = -1;
    for (int i = 0; i < numOfSongs; ++i) {
        if (songs[i].title == titleToDelete) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1) {
        Song* newSongs = new Song[numOfSongs - 1];
        int newIndex = 0;
        for (int i = 0; i < numOfSongs; ++i) {
            if (i != indexToDelete) {
                newSongs[newIndex] = songs[i];
                newIndex++;
            }
        }

        delete[] songs;
        songs = newSongs;
        numOfSongs--;
        cout << "Пісня з назвою '" << titleToDelete << "' видалена.\n";
    }
    else {
        cout << "Пісня з назвою '" << titleToDelete << "' не знайдена.\n";
    }
}

void editLyrics(Song& song) {
    cout << "Введіть новий текст пісні:\n";
    inputLyricsFromConsole(song);
}

void displayAllLyrics(const Song* songs, int numOfSongs) {
    cout << "\nВсі тексти пісень:\n";
    for (int i = 0; i < numOfSongs; ++i) {
        cout << "Текст пісні '" << songs[i].title << "':\n";
        cout << songs[i].lyrics << "\n\n";
    }
}

void saveSongToFile(const Song& song, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "Назва пісні: " << song.title << "\n";
        file << "Автор пісні: " << song.author << "\n";
        file << "Рік створення пісні: " << song.year << "\n";
        file << "Текст пісні:\n" << song.lyrics;
        file.close();
        cout << "Пісня збережена в файлі.\n";
    }
    else {
        cout << "Не вдалося відкрити файл для збереження пісні.\n";
    }
}

void addNewSong(Song* songs, int& numOfSongs) {
    if (numOfSongs < 100) {
        cout << "Введіть дані про нову пісню:\n";
        cout << "Назва пісні: ";
        cin >> songs[numOfSongs].title;

        cout << "Автор пісні: ";
        cin >> songs[numOfSongs].author;

        cout << "Текст пісні: ";
        inputLyricsFromConsole(songs[numOfSongs]);

        cout << "Рік створення пісні: ";
        cin >> songs[numOfSongs].year;

        saveSongToFile(songs[numOfSongs], "songs.txt");

        ++numOfSongs;

        cout << "Нова пісня додана та збережена в файлі.\n";
    }
    else {
        cout << "Досягнута максимальна кількість пісень.\n";
    }
}

void displaySongsByAuthor(const Song* songs, int numOfSongs, const string& author) {
    cout << "\nПісні автора '" << author << "':\n";
    bool found = false;

    for (int i = 0; i < numOfSongs; ++i) {
        if (songs[i].author == author) {
            found = true;
            cout << "Назва: " << songs[i].title << endl;
            cout << "Автор: " << songs[i].author << endl;
            cout << "Рік створення: " << songs[i].year << endl;
            cout << "Текст пісні: " << songs[i].lyrics << endl << endl;
        }
    }

    if (!found) {
        cout << "Пісень від автора '" << author << "' не знайдено.\n";
    }
}

void searchSongsByWord(const Song* songs, int numOfSongs, const string& searchWord) {
    cout << "\nПісні, які містять слово '" << searchWord << "':\n";
    bool found = false;

    for (int i = 0; i < numOfSongs; ++i) {
        bool wordFound = false;
        for (int j = 0; j <= songs[i].lyrics.size() - searchWord.size(); ++j) {
            bool match = true;
            for (int k = 0; k < searchWord.size(); ++k) {
                if (songs[i].lyrics[j + k] != searchWord[k]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                wordFound = true;
                break;
            }
        }

        if (wordFound) {
            found = true;
            cout << "Назва: " << songs[i].title << endl;
            cout << "Автор: " << songs[i].author << endl;
            cout << "Рік створення: " << songs[i].year << endl;
            cout << "Текст пісні: " << songs[i].lyrics << endl << endl;
        }
    }

    if (!found) {
        cout << "Пісень, які містять слово '" << searchWord << "', не знайдено.\n";
    }
}

void exitProgram() {
    cout << "До побачення! Програма завершила роботу.\n";
    exit(0);
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    const int MAX_SONGS = 100;
    Song* songs = new Song[MAX_SONGS];
    int numOfSongs = 0;
    int songToEdit;

    char choice;

    while (true) {
        cout << "Оберіть дію:\n";
        cout << "1. Додати нову пісню\n";
        cout << "2. Видалити пісню\n";
        cout << "3. Змінити текст пісні\n";
        cout << "4. Відобразити текст всіх пісень\n";
        cout << "5. Відобразити пісні одного автора\n";
        cout << "6. Пошук пісень за словом у тексті\n";
        cout << "7. Вийти з програми\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == '1') {
            addNewSong(songs, numOfSongs);
        }
        else if (choice == '2') {
            string titleToDelete;
            cout << "Введіть назву пісні для видалення: ";
            cin >> titleToDelete;
            deleteSong(songs, numOfSongs, titleToDelete);
        }
        else if (choice == '3') {
            if (numOfSongs > 0) {
                cout << "Оберіть пісню для зміни тексту (введіть номер пісні): ";
                cin >> songToEdit;
                if (songToEdit >= 0 && songToEdit < numOfSongs) {
                    editLyrics(songs[songToEdit]);
                    cout << "Текст пісні змінено.\n";
                }
                else {
                    cout << "Неправильний номер пісні.\n";
                }
            }
            else {
                cout << "Немає жодної пісні для зміни тексту.\n";
            }
        }
        else if (choice == '4') {
            displayAllLyrics(songs, numOfSongs);
        }
        else if (choice == '5') {
            string author;
            cout << "Введіть ім'я автора для відображення його пісень: ";
            cin >> author;
            displaySongsByAuthor(songs, numOfSongs, author);
        }
        else if (choice == '6') {
            string searchWord;
            cout << "Введіть слово для пошуку у тексті пісень: ";
            cin >> searchWord;
            searchSongsByWord(songs, numOfSongs, searchWord);
        }
        else if (choice == '7') {
            exitProgram();
        }
        else {
            cout << "Неправильний вибір. Будь ласка, оберіть правильну дію.\n";
        }
    }


    delete[] songs;
    return 0;
}






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
