
#Interpreter
	##FileReader => 
		* ask the user the name or path to the file to open.
		* read the file.
		* split the lines in the file.
		* return a vector of strings, each element is one line of the file.
	
	##Parser => 
		* split each line into function name and arguments. line must match: "^\w{3}\<.+?\>$"
		* verify that the function name is 3 characters long.
		* verify that the arguments are separated using snake_case.
		* verify that each argument is a valid expression :
			- string
			- number
			- variable
			- antoher function call, with valid arguments.

		* create a tree of tokens for the statement of the line. Examples:
			- out<,hello_world,>  -->  PRINT( STRING("hello_world") ); // cout << "hello_world";
			- out<sum<5_12>>      -->  PRINT( SUM( NUMBER(5), NUMBER(12) ) ); // cout << 5 + 12 ;
			- out<mul<10_in<>>>   -->  PRINT( MUL( NUMBER(10), INPUT() ) ); // cin>>n; cout << 10 * n;
			- set<num_42>	      -->  DEFINE( NAME("num"), NUMBER(42) ); // int num = 42 ;

##_Tokens_ :
	- OUT (arg)   => cout << arg << endl;
	- INP ()      => { std::string x; cin >> x; return x; }
	- SET (k, v)  => { let k = v; return null; }
	- SUM (args)  => args.reduce((a, b) => a + b);
	- RES (a, b)  => a - b;
	- MUL (a, b)  => a * b;
	- DIV (a, b)  => a / b;
	
