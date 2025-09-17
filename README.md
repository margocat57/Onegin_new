# Eugene Onegin: The Encyclopedia of Russian Life in Code

Vissarion Belinsky, the renowned Russian literary critic, famously described Alexander Pushkin's novel in verse "Eugene Onegin" as an "encyclopedia of Russian life" in his seminal article. This characterization remains profoundly influential to this day, compelling literature teachers worldwide to assign essays on the topic "Eugene Onegin as an encyclopedia of Russian life."

While we acknowledge the literary significance of Pushkin's masterpiece, we approach this task from a programmer's perspective. For us, an encyclopedia represents an ordered collection of information. If "Eugene Onegin" truly constitutes an encyclopedia, its lines should follow alphabetical organization.

An intriguing extension of this concept involves developing a text generator capable of producing Pushkin-style verse. This application would benefit from sorting capabilities in both standard and reverse alphabetical orders.

## Project Implementation

This project implements:
- File parsing functionality that reads the novel's lines into a string array
- Pointer array construction referencing the original text lines
- Cocktail shaker sort algorithm utilizing comparator functions
- Flexible sorting through function pointers that determine ordering criteria
- Output generation presenting text in three distinct arrangements:
  - Alphabetical order
  - Reverse alphabetical order
  - Original source sequence

## Build and Execution

Clone the repository:
```bash
git clone https://github.com/your-username/eugene-onegin-sorter.git
