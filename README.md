# DotMatic: A Braille Printer

DotMatic is a compact and user-friendly braille printer designed to improve access to braille. With its affordable, portable design, DotMatic provides a practical solution for creating braille documents and enhancing accessibility in everyday life.

https://github.com/user-attachments/assets/3e55ad5c-6397-4724-b218-f87f492b8c51

---

## Project Overview  
DotMatic translates text into braille alphabet patterns and prints them onto paper using a precise, motor-driven system. The design prioritizes simplicity, portability, and cost-effectiveness, making it ideal for classrooms and homes.  

---

## Materials Used  
### Hardware  
- **LEGO EV3 Brick**: The core computing unit.  
- **LEGO Servo Motors (x3)**: Provides controlled movement for precise braille printing.  
- **Touch Sensor**: Used for user interaction and operational control.  
- **Laser-Cut Gear Racks (x2)**: Custom-made for smooth and accurate linear motion.  
- **Foam Paper**: Acts as the base below paper.

### Software  
- **Programming Language**: RobotC was used to develop the control logic and manage motor/sensor interactions.  

---

## Key Features  
- **Child-Friendly Design**: Portable, small, and intuitive, tailored for kindergarten-aged students.  
- **Affordable**: Built with widely available LEGO components.
- **Modular Construction**: Easy to assemble and modify, encouraging experimentation and learning.  

---
## How It Works  

### Understanding Braille Printing  
Braille is composed of characters with up to 3 rows and 2 columns of raised dots per letter. DotMatic translates text into this tactile system and prints it on paper using precise motor control and a custom-designed mechanism.  
![image](https://github.com/user-attachments/assets/0368413c-44db-4566-a757-9dbd0af59d9b)


---

### Before Printing  
1. **Text File Formatting**:  
   - Separate each word with a `/`.  
   - End each sentence with a `!`.  

   Example: `hello/world!`  

2. **Setting Up**:  
   - Place paper into the printer and secure it under the frame.  

---

### Printing Process  
1. **Starting the Program**:  
   - The LEGO EV3 brick displays the message asking the user to press the Enter button to start
   - Once the user presses the "Enter" button, the program begins reading the formatted text file.  

2. **Printing the First Braille Row**:  
   - For each word in the sentence:  
     - The crank moves down to punch the first dot.  
     - The crank moves back up.  
     - The cart shifts horizontally by 2.5 mm (the distance between Braille dots).  
     - This process repeats for all dots in the first row.  
   - When a `/` (word separator) is encountered, the cart creates a space by moving the distance of one letter.  
   - After completing a word, the cart moves back to its starting position.  

3. **Transition to the Next Row**:  
   - The paper rolls forward by 2.5 mm to position for the second row.  
   - The second row of the sentence is printed using the same process as above.  
   - After completing the second row, the cart resets, and the third row is printed.  

4. **Efficiency Consideration**:  
   - The robot prints each braille row for the entire sentence before moving to the next row. This minimizes unnecessary movement and improves stability.  

5. **Completion**:  
   - Once printing is finished, the LEGO EV3 brick displays *"System Complete."*  
   - The user must press the "Down" button to stop the system.  
   - The paper can then be removed and flipped to read the printed braille.
   - ![WhatsApp Image 2024-11-20 at 17 33 58_9284ea73](https://github.com/user-attachments/assets/336b2a99-8757-45dd-adef-6feeb6a0dcaf)


---

### Emergency Stop  
- The touch sensor constantly monitors for an emergency stop signal.  
- If pressed:  
  - All motors immediately stop.  
  - The EV3 brick displays an *"Emergency Stop"* message.  
  - After 5 seconds, the program rolls the paper out for easy removal.  

---
DotMatic demonstrates the potential of using robotics to make education more accessible and inclusive, paving the way for innovative solutions in assistive technology.
