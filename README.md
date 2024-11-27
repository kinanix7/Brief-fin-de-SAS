Here is a README file for your project, formatted for GitHub:

```markdown
# Task Management System

This is a simple **Task Management System** implemented in C. The program allows users to manage tasks by adding, displaying, modifying, deleting, and filtering them. Tasks are stored in a predefined structure and are managed through a menu-based interface.

## Features

- **Add Task:** Add a new task with details like title, description, due date, priority, and status.
- **Display Tasks:** View all existing tasks.
- **Modify Task:** Edit the details of an existing task.
- **Delete Task:** Remove a task from the list.
- **Filter Tasks:** View tasks filtered by priority (`high` or `low`).

## Structure of a Task

Each task includes the following fields:
- `id`: A unique identifier for the task.
- `title`: Title of the task (up to 50 characters).
- `description`: Description of the task (up to 100 characters).
- `dataEcheance`: Due date in the format `DD-MM-YYYY`.
- `priorite`: Priority level (`high` or `low`).
- `statue`: Task status (`complete` or `incomplete`).

## How to Compile and Run

1. Clone this repository or copy the source code into a file, e.g., `task_manager.c`.
2. Compile the code using a C compiler:
   ```bash
   gcc task_manager.c -o task_manager
   ```
3. Run the compiled program:
   ```bash
   ./task_manager
   ```

## Usage

1. **Run the Program:** After running the program, a menu will be displayed:
   ```
   Menu:
   1. Ajouter
   2. Afficher
   3. Modifier
   4. Supprimer
   5. Filtrer
   6. Quitter
   ```
2. **Choose an Option:** Enter the number corresponding to your choice and follow the prompts.
3. **Exit:** Select option `6` to exit the program.

## Example Interaction

Here is an example of how to use the program:

1. Add a task:
   ```
   Entrez le titre de la tache: Example Task
   Entrez la description de la tache: This is an example task.
   Entrez la date de la tache (DD/MM/YYYY): 01/12/2024
   Entrez la priorite de la tache (high/low): high
   Entrez la statue de la tache (complete/incomplete): incomplete
   ```

2. Display tasks:
   ```
   ---------------------------------------------------------
   Id: 1
   Titre: Example Task
   Description: This is an example task.
   DataEcheance: 01/12/2024
   Priorite: high
   Statut: incomplete
   ---------------------------------------------------------
   ```

3. Modify a task, delete a task, or filter tasks as required.

## Limitations

- The maximum number of tasks is set to `100`.
- Data is stored in memory and will not persist after the program exits.

## Contributing

Feel free to fork this repository, add new features, fix bugs, or improve code readability. Submit a pull request with your changes.

## License

This project is open-source and available under the [MIT License](LICENSE).
```

Replace `LICENSE` with the appropriate link or content if you have a specific license for your project.
