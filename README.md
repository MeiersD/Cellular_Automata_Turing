### Demo
[![Cellular Automata Turing Machine Demo](https://img.youtube.com/vi/PIkwhJi1-7A/0.jpg)](https://m.youtube.com/watch?v=PIkwhJi1-7A)

# Building a Turing Machine using Cellular Automata
Hi everyone, I made this project because I wanted to practice C. This whole thing is a binary calculator, meaning you can add two integers together. The way the numbers are added is special. Instead of using normal code like a+b, I am using a Turing Maching powered by Cellular Automata. I got the idea from Martinez et al's paper (pdf linked in repo). I basically tried to emulate their figure 1 using table 3 as a reference.

I am quite positive that Table 3 is wrong, but I figured it out. The authors made a typo. I will email them about it later, hopefully they will respond. Basically, the rule for OAD when the head sees a 0 should be to write a b, not a B. b is the locked in symbol for 1, and B is blank. In my code, I switched out the lower case b for an x so it is easier to tell them apart.

I also included an image of the table so you dont have to open the pdf if you dont want to.

## How it works
The black square is the head of the Turing Machine, the blue squares are blank cells, and the purple/green squares are cells with values (1 or 0 respectively). The head cell may always be black, but it is changing. You can't see it but it does. I'll touch more on this point in the next paragraph. Another note: the head points to the cell to the right. Traditional turning machines have a head which hovers over the tape and rewrites the symbol, but in cellular automata, the head must also exist on the tape itself.

To expand on the cryptic "IT CHANGES" statement: The head cell is always black, but the actual symbol on the tape is changing. Basically, for all other cells besides the head, the color represents a symbol on the tape ('=', '0', '1', '+', 'B', 'y', 'x') but rather than call the head 'h', we can store extra information in the tape by changing the symbol which represents the head depending on the head's state. So the multiple tape symbols encode for the same black square, which represents the head.

What is a state? A state is basically a mode the Turing Machine is in. The state tells the head what to do when it sees a certain symbol. For example, if the head is in state q0 and it sees a 0, it will write a 1, move right, and change to state q1. If the head is in state q1 and it sees a 0, it will write a 0, move left, and change to state q0. That's just an example that github copilot wrote, but you get the idea.

## Other notes:
When you run the code, you will see the head zig zagging across the tape. The head always moves to the left or the right, so that's why it looks like that. In general, the head moves over to the end of the second number, scoops up the carry, then moves back to the beginning of the tape to write the result. It then locks in the right-most bit on the first number and moves back to the end of the second number to scoop up the next carry. It repeats this until it is done adding.

### Colors:
- Black: Head (can be in any state from a-m, there are 13 states)
- Tan: =
- Blue: Blank (B)
- Green: 0
- Purple: 1
- Periwinkle: +
- Aquamarine: Locked/finalized 0
- Dark Teal: Locked/finalized 1
