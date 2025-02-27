# CS_210

* Summarize the project and what problem it was solving.

This project is a simple investment calculator meant to demonstrate the power of compound interest. From the console, the user enters four things: an initial investment amount, a recurring monthly deposit amount, the annual interest rate, and the life of the investment in years. The annual interest rate is compounded monthly. From there, two separate reports get printed. The first is a breakdown of year-end balances and interest earned over each year of the loan without the recurring monthly deposits. The second report simply adds the monthly deposits. 

* What did you do particularly well?

The project is broken down, essentially, into two components - the Investment class and the main application. The class is very simple. It manages the basic data of the investment (initial deposit, interest rate, etc.), and its only complex task is generating the two reports. The main application handles the user menu, user I/O, and interacts with the Investment class through a handful of method calls. Overall I think the separation between the two was handled fairly cleanly, and it lends itself to readability/maintainability.

There were a couple of interesting things I tried this project that I think turned out pretty well. The first was an attempt at an extremely simple cross-platform console special effects library. This successfully added color to the printed console text and allowed the cursor to be moved around for line rewriting. I would like to continue developing this library in the future. 

The second was a novel (to me) way of handling user input validation. In the main application file (main.cpp), separate functions were created that explicitiy handled input validation based on the type the application needed - int, double, etc. The function parameter was type string which allows one to pass a unique user prompt each time the function is called. This also allows one to insert input validation wherever it is needed in a relatively unobtrusive manner. Overall, this approach could be templatized or extended in a number of ways and I plan on refining it in the future. 

* Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

One area of improvement could be to fix the problem of rounding floating-point numbers to dollars and cents. I am unfamiliar with what financial applications typically use. That could be some sort of fixed-point numerical system where there aren't really any fractional values. 

Another related area of improvement is to introduce bounds checking on all arithmetic variables used. This would prevent overflow which can introduce run-time errors and could even introduce security issues (if this application were ever extended and used in any real way).

* Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

User input validation was the most challenging aspect of this project. Keeping it separated in a clean way, and responding when invalid input is detected seems to always be a challenge. I overcame this with the functions I mentioned earlier.  
  
* What skills from this project will be particularly transferable to other projects or course work?

The implementation and use of classes/objects is definitely a transferable skill moving forward. I spent a good deal of time trying to strike a balance between what could should and should not exist in the class - and what code should and should not exist in the application. They are necessarily coupled as they need one another to function, but I feel like I've improved in implementing that relationship, which is another useful skill. 
  
* How did you make this program maintainable, readable, and adaptable?

For one, I made a conscious effort to liberally comment the code. That is not something I have done in the past and I am trying to improve in that aspect. I also tried to keep every section of the code (method, function, etc.) simple to the point that it is self-contained and easily modified, but also extensible if someone wished to do so in the future. 
