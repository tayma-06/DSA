#include <bits/stdc++.h>
using namespace std;

class UndoRedo
{
private:
    string currentText = "";
    deque<string> undoStack;
    deque<string> redoStack;

public:
    void edit(const string &newText)
    {
        undoStack.push_back(currentText);
        currentText = newText;
        redoStack.clear();
    }
    void undo()
    {
        if (!undoStack.empty())
        {
            redoStack.push_back(currentText);
            currentText = undoStack.back();
            undoStack.pop_back();
        }
        else
        {
            cout << "No more undo available.\n";
        }
    }
    void redo()
    {
        if (!redoStack.empty())
        {
            undoStack.push_back(currentText);
            currentText = redoStack.back();
            redoStack.pop_back();
        }
        else
        {
            cout << "No more redo available.\n";
        }
    }
    string getText() const
    {
        return currentText;
    }
};

int main()
{
    UndoRedo editor;

    editor.edit("Hello");
    editor.edit("Hello World");
    editor.edit("Hello World!!!");

    cout << "Current: " << editor.getText() << endl;

    editor.undo();
    cout << "Undo:    " << editor.getText() << endl;

    editor.undo();
    cout << "Undo:    " << editor.getText() << endl;

    editor.redo();
    cout << "Redo:    " << editor.getText() << endl;

    return 0;
}