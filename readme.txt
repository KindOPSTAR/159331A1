//read me info.
/*
This is an assignment of massey university, which is done by HE ZHANG, 16216941 for 159331.
This program can used solving common issue of information entry and enquiries.

When you use it, please open c file which called "assignment_1_159331(workingonv2).c" first or just click .exe file to run.

Please complie and run after Environment configuration.

This assignment .c file can run in with gcc(SciTE).*/

//----------------------------------------------------------------------------------
/*
Use this .c file, please followed input specification below.

	You can enter:
		set name "information";  
		// ---- for set information into buffer name;
		set new_name nameA + SPACE/TAB/NEWLINE + nameB
		// ---- for set combo included in information of buffer nameA, symbol and information of buffer nameB into new_name;
		list;		
		// ---- list all buffer you have entered (print link-list)
		append name "more information";
		// ---- append more information into buffer name. 
		print name;
		// ---- print information of in buffer name;
		printwordcount name;
		// ---- print the count of words about information of in buffer name;
		printwords name;
		// ---- print each word about information of in buffer name;
		printlength name;
		// ---- print the length of whole information of in buffer name;
		reverse name;
		// ---- reversed the information of in buffer name.
		exit;
		// ---- stop running program.
*/
//----------------------------------------------------------------------------------

/*
The .c file included in actually two methoed of solution.
The method of current running, used function to get each word of input.
e.g. using loop to read input. output wrod(find keyword/find name/find information) by calculated length and specific symbol.

The method of in reference parts, used strcmp(), strstr(), strtok(), etc. functions to find keywords, buffer_name and input_information. (This method is run not perfect, bucause author did not find a good solution for copying(or transfering) between type char and char*.)

Notes: some definition is unused in program because some of them are both definition for two methods nevertheless some are used by specially. Please ignore it if anything did not use.
*/

//----------------------------------------------------------------------------------

/*
This program is working followed checking user's input by find unique key and call associated function. 
*/