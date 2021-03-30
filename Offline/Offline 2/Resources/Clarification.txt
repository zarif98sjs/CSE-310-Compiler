Inclusive state problem clarification:
---------------------------------------

In the class, I faced a problem (1:21:17 in video) while running the code with inclusive state (warning of rule cannot be matched). It turns out that flex gives such a warning when it finds the same active rule twice or more. Here, as there is the rule [ \t\n]+ both in the initial state and MYSTATE, it gets confused which rule it should apply (apparently it doesnt consider which is above in this case). Removing any one of the rule when MYSTATE is inclusive gets the warning removed. When MYSTATE is exclusive then this problem doesn't occur, as then the rule in initial state is inactive.

Not only in this case, but in any case if it finds the two same pattern active and matches it, it generates such warnings (as one student asked earlier in the class at 31:41). Moral of the story, don't write the same pattern rule twice or more that can be active simultaneously. 

Where would I probably need to use start states?
------------------------------------------------

You will most probably need them when you are writing expressions for string, single-line & multiline comments. It is also acceptable if you can give the proper outputs even without using start states, however it might turn out to be too complex.