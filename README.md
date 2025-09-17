# Eugene Onegin: Encyclopedia of Russian Life in Code

Vissarion Belinsky, the renowned Russian literary critic, famously described Alexander Pushkin's novel in verse "Eugene Onegin" as an "encyclopedia of Russian life" in his seminal article. This characterization remains profoundly influential to this day, compelling literature teachers worldwide to assign essays on the topic "Eugene Onegin as an encyclopedia of Russian life."

While we acknowledge the literary significance of Pushkin's masterpiece, we approach this task from a programmer's perspective. For us, an encyclopedia represents an ordered collection of information. If "Eugene Onegin" truly constitutes an encyclopedia, its lines should follow alphabetical organization.

An intriguing extension of this concept involves developing a text generator capable of producing Pushkin-style verse. This application would benefit from sorting capabilities in both standard and reverse alphabetical orders.

## What this project does

- Reads lines from the novel file into array
- Makes array of pointers to these lines
- Uses cocktail shaker sort with comparator function
- Comparator function decides sorting order
- Shows results in three ways:
  - Alphabetical order
  - Reverse alphabetical order
  - Original text order

## How to use

First, copy the project:

```bash
git clone https://github.com/your-username/eugene-onegin-sorter.git
```

Build the project:
```bash
make
```

Run the program:
```bash
./onegin
```

Clean build files:
```bash
make clean
```



