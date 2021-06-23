#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////
//	Jacob Rowan				
//	Fletcher van Ameringen	
//	Samual Yap-Choong		
//Initialise Fuzzy Rules

/*
in_nl = input negative large (left side)
in_ns = input negative small (left side)
in_ze = input zero (centered) (left side)
in_ps = input positive small (right side)
in_pl = input positive large (right side)
*/

void initFuzzyRules(fuzzy_system_rec *fl) {
	
   const int
      no_of_x_rules = 25,
      no_of_theta_rules = 25;
   
   int i;
	
//---------------------------------------------------------------------------- 	
//THETA vs. THETA_DOT	
//   
   for (i = 0;i < no_of_theta_rules;i++) {
       fl->rules[i].inp_index[0] = in_theta;
       fl->rules[i].inp_index[1] = in_theta_dot;
   }
	      
	/*
	Note that inp_index has a corresponding array: inp_fuzzy_set	
	Below we are essentially stating the FAMM grid / rules we drew as coded rules
	*/

   // NEW EXPERIMENTAL RULES, INCREASED EFFECT OF ANGLE
   /*********************************************** ROW #1 *********************************************/
	fl->rules[0].inp_fuzzy_set[0] = in_nl;
	fl->rules[0].inp_fuzzy_set[1] = in_nl;
	fl->rules[1].inp_fuzzy_set[0] = in_ns;
	fl->rules[1].inp_fuzzy_set[1] = in_nl;
	fl->rules[2].inp_fuzzy_set[0] = in_ze;
	fl->rules[2].inp_fuzzy_set[1] = in_nl;
	fl->rules[3].inp_fuzzy_set[0] = in_ps;
	fl->rules[3].inp_fuzzy_set[1] = in_nl;
	fl->rules[4].inp_fuzzy_set[0] = in_pl;
	fl->rules[4].inp_fuzzy_set[1] = in_nl;
	// OUTPUT
	fl->rules[0].out_fuzzy_set = out_nvl;
	fl->rules[1].out_fuzzy_set = out_nvl;
	fl->rules[2].out_fuzzy_set = out_nm;
	fl->rules[3].out_fuzzy_set = out_ns;
	fl->rules[4].out_fuzzy_set = out_pvl;
	
	/*********************************************** ROW #2 *********************************************/
	fl->rules[5].inp_fuzzy_set[0] = in_nl;
	fl->rules[5].inp_fuzzy_set[1] = in_ns;
	fl->rules[6].inp_fuzzy_set[0] = in_ns;
	fl->rules[6].inp_fuzzy_set[1] = in_ns;
	fl->rules[7].inp_fuzzy_set[0] = in_ze;
	fl->rules[7].inp_fuzzy_set[1] = in_ns;
	fl->rules[8].inp_fuzzy_set[0] = in_ps;
	fl->rules[8].inp_fuzzy_set[1] = in_ns;
	fl->rules[9].inp_fuzzy_set[0] = in_pl;
	fl->rules[9].inp_fuzzy_set[1] = in_ns;
	// OUTPUT
	fl->rules[5].out_fuzzy_set = out_nvl;
	fl->rules[6].out_fuzzy_set = out_nl;
	fl->rules[7].out_fuzzy_set = out_ns;
	fl->rules[8].out_fuzzy_set = out_ze;
	fl->rules[9].out_fuzzy_set = out_ps;
	
	/*********************************************** ROW #3 *********************************************/
	fl->rules[10].inp_fuzzy_set[0] = in_nl;
	fl->rules[10].inp_fuzzy_set[1] = in_ze;
	fl->rules[11].inp_fuzzy_set[0] = in_ns;
	fl->rules[11].inp_fuzzy_set[1] = in_ze;
	fl->rules[12].inp_fuzzy_set[0] = in_ze; // ZERO
	fl->rules[12].inp_fuzzy_set[1] = in_ze; // ZERO
	fl->rules[13].inp_fuzzy_set[0] = in_ps;
	fl->rules[13].inp_fuzzy_set[1] = in_ze;
	fl->rules[14].inp_fuzzy_set[0] = in_pl;
	fl->rules[14].inp_fuzzy_set[1] = in_ze;
	// OUTPUT
	fl->rules[10].out_fuzzy_set = out_nl;
	fl->rules[11].out_fuzzy_set = out_nm;
	fl->rules[12].out_fuzzy_set = out_ze;
	fl->rules[13].out_fuzzy_set = out_pm;
	fl->rules[14].out_fuzzy_set = out_pl;
	
	/*********************************************** ROW #4 *********************************************/
	fl->rules[15].inp_fuzzy_set[0] = in_nl;
	fl->rules[15].inp_fuzzy_set[1] = in_ps; 
	fl->rules[16].inp_fuzzy_set[0] = in_ns; 
	fl->rules[16].inp_fuzzy_set[1] = in_ps;
	fl->rules[17].inp_fuzzy_set[0] = in_ze;
	fl->rules[17].inp_fuzzy_set[1] = in_ps;
	fl->rules[18].inp_fuzzy_set[0] = in_ps;
	fl->rules[18].inp_fuzzy_set[1] = in_ps;
	fl->rules[19].inp_fuzzy_set[0] = in_pl; 
	fl->rules[19].inp_fuzzy_set[1] = in_ps;
	// OUTPUT
	fl->rules[15].out_fuzzy_set = out_ns;
	fl->rules[16].out_fuzzy_set = out_ze;
	fl->rules[17].out_fuzzy_set = out_ps;
	fl->rules[18].out_fuzzy_set = out_pl;
	fl->rules[19].out_fuzzy_set = out_pvl;

	/*********************************************** ROW #5 *********************************************/
	fl->rules[20].inp_fuzzy_set[0] = in_nl;
	fl->rules[20].inp_fuzzy_set[1] = in_pl;
	fl->rules[21].inp_fuzzy_set[0] = in_ns;
	fl->rules[21].inp_fuzzy_set[1] = in_pl; 
	fl->rules[22].inp_fuzzy_set[0] = in_ze;
	fl->rules[22].inp_fuzzy_set[1] = in_pl;
	fl->rules[23].inp_fuzzy_set[0] = in_ps;
	fl->rules[23].inp_fuzzy_set[1] = in_pl;
	fl->rules[24].inp_fuzzy_set[0] = in_pl;
	fl->rules[24].inp_fuzzy_set[1] = in_pl; 
	// OUTPUT
	fl->rules[20].out_fuzzy_set = out_nvl;
	fl->rules[21].out_fuzzy_set = out_ps;
	fl->rules[22].out_fuzzy_set = out_pm;
	fl->rules[23].out_fuzzy_set = out_pvl;
	fl->rules[24].out_fuzzy_set = out_pvl;
	
//----------------------------------------------------------------------------   
//X vs. X_DOT
//
   for (i = 0;i < no_of_x_rules;i++) {
   	  fl->rules[i + no_of_theta_rules].inp_index[0] = in_x;
   	  fl->rules[i + no_of_theta_rules].inp_index[1] = in_x_dot;
	}

	//ORIGINAL VALUES
	/*********************************************** ROW #1 *********************************************/
	fl->rules[no_of_theta_rules+0].inp_fuzzy_set[0] = in_nl;
	fl->rules[no_of_theta_rules+0].inp_fuzzy_set[1] = in_nl;
	fl->rules[no_of_theta_rules+1].inp_fuzzy_set[0] = in_ns;
	fl->rules[no_of_theta_rules+1].inp_fuzzy_set[1] = in_nl;
	fl->rules[no_of_theta_rules+2].inp_fuzzy_set[0] = in_ze;
	fl->rules[no_of_theta_rules+2].inp_fuzzy_set[1] = in_nl;
	fl->rules[no_of_theta_rules+3].inp_fuzzy_set[0] = in_ps;
	fl->rules[no_of_theta_rules+3].inp_fuzzy_set[1] = in_nl;
	fl->rules[no_of_theta_rules+4].inp_fuzzy_set[0] = in_pl;
	fl->rules[no_of_theta_rules+4].inp_fuzzy_set[1] = in_nl;
	// OUTPUT	
	fl->rules[no_of_theta_rules+0].out_fuzzy_set = out_pvl;
	fl->rules[no_of_theta_rules+1].out_fuzzy_set = out_pm;
	fl->rules[no_of_theta_rules+2].out_fuzzy_set = out_ns;
	fl->rules[no_of_theta_rules+3].out_fuzzy_set = out_nm;
	fl->rules[no_of_theta_rules+4].out_fuzzy_set = out_nl;
	
	/*********************************************** ROW #2 *********************************************/
	fl->rules[no_of_theta_rules+5].inp_fuzzy_set[0] = in_nl;
	fl->rules[no_of_theta_rules+5].inp_fuzzy_set[1] = in_ns;
	fl->rules[no_of_theta_rules+6].inp_fuzzy_set[0] = in_ns;
	fl->rules[no_of_theta_rules+6].inp_fuzzy_set[1] = in_ns;
	fl->rules[no_of_theta_rules+7].inp_fuzzy_set[0] = in_ze;
	fl->rules[no_of_theta_rules+7].inp_fuzzy_set[1] = in_ns;
	fl->rules[no_of_theta_rules+8].inp_fuzzy_set[0] = in_ps;
	fl->rules[no_of_theta_rules+8].inp_fuzzy_set[1] = in_ns;
	fl->rules[no_of_theta_rules+9].inp_fuzzy_set[0] = in_pl;
	fl->rules[no_of_theta_rules+9].inp_fuzzy_set[1] = in_ns;
	// OUTPUT
	fl->rules[no_of_theta_rules+5].out_fuzzy_set = out_pm;
	fl->rules[no_of_theta_rules+6].out_fuzzy_set = out_ns;
	fl->rules[no_of_theta_rules+7].out_fuzzy_set = out_nl;
	fl->rules[no_of_theta_rules+8].out_fuzzy_set = out_nm;
	fl->rules[no_of_theta_rules+9].out_fuzzy_set = out_ze;
	
	/*********************************************** ROW #3 *********************************************/
	fl->rules[no_of_theta_rules+10].inp_fuzzy_set[0] = in_nl;
	fl->rules[no_of_theta_rules+10].inp_fuzzy_set[1] = in_ze;
	fl->rules[no_of_theta_rules+11].inp_fuzzy_set[0] = in_ns;
	fl->rules[no_of_theta_rules+11].inp_fuzzy_set[1] = in_ze;
	fl->rules[no_of_theta_rules+12].inp_fuzzy_set[0] = in_ze; // ZERO
	fl->rules[no_of_theta_rules+12].inp_fuzzy_set[1] = in_ze; // ZERO
	fl->rules[no_of_theta_rules+13].inp_fuzzy_set[0] = in_ps;
	fl->rules[no_of_theta_rules+13].inp_fuzzy_set[1] = in_ze;
	fl->rules[no_of_theta_rules+14].inp_fuzzy_set[0] = in_pl;
	fl->rules[no_of_theta_rules+14].inp_fuzzy_set[1] = in_ze;
	// OUTPUT
	fl->rules[no_of_theta_rules+10].out_fuzzy_set = out_nm;
	fl->rules[no_of_theta_rules+11].out_fuzzy_set = out_ns;
	fl->rules[no_of_theta_rules+12].out_fuzzy_set = out_ze;
	fl->rules[no_of_theta_rules+13].out_fuzzy_set = out_ps;
	fl->rules[no_of_theta_rules+14].out_fuzzy_set = out_pm;

	/*********************************************** ROW #4 *********************************************/
	fl->rules[no_of_theta_rules+15].inp_fuzzy_set[0] = in_nl;
	fl->rules[no_of_theta_rules+15].inp_fuzzy_set[1] = in_ps; 
	fl->rules[no_of_theta_rules+16].inp_fuzzy_set[0] = in_ns; 
	fl->rules[no_of_theta_rules+16].inp_fuzzy_set[1] = in_ps;
	fl->rules[no_of_theta_rules+17].inp_fuzzy_set[0] = in_ze;
	fl->rules[no_of_theta_rules+17].inp_fuzzy_set[1] = in_ps;
	fl->rules[no_of_theta_rules+18].inp_fuzzy_set[0] = in_ps;
	fl->rules[no_of_theta_rules+18].inp_fuzzy_set[1] = in_ps;
	fl->rules[no_of_theta_rules+19].inp_fuzzy_set[0] = in_pl; 
	fl->rules[no_of_theta_rules+19].inp_fuzzy_set[1] = in_ps;
	// OUTPUT
	fl->rules[no_of_theta_rules+15].out_fuzzy_set = out_ze;
	fl->rules[no_of_theta_rules+16].out_fuzzy_set = out_pm;
	fl->rules[no_of_theta_rules+17].out_fuzzy_set = out_pl;
	fl->rules[no_of_theta_rules+18].out_fuzzy_set = out_ps;
	fl->rules[no_of_theta_rules+19].out_fuzzy_set = out_nm;

	/*********************************************** ROW #5 *********************************************/
	fl->rules[no_of_theta_rules+20].inp_fuzzy_set[0] = in_nl;
	fl->rules[no_of_theta_rules+20].inp_fuzzy_set[1] = in_pl;
	fl->rules[no_of_theta_rules+21].inp_fuzzy_set[0] = in_ns;
	fl->rules[no_of_theta_rules+21].inp_fuzzy_set[1] = in_pl; 
	fl->rules[no_of_theta_rules+22].inp_fuzzy_set[0] = in_ze;
	fl->rules[no_of_theta_rules+22].inp_fuzzy_set[1] = in_pl;
	fl->rules[no_of_theta_rules+23].inp_fuzzy_set[0] = in_ps;
	fl->rules[no_of_theta_rules+23].inp_fuzzy_set[1] = in_pl;
	fl->rules[no_of_theta_rules+24].inp_fuzzy_set[0] = in_pl;
	fl->rules[no_of_theta_rules+24].inp_fuzzy_set[1] = in_pl;
	// OUTPUT
	fl->rules[no_of_theta_rules+20].out_fuzzy_set = out_pl;
	fl->rules[no_of_theta_rules+21].out_fuzzy_set = out_pm;
	fl->rules[no_of_theta_rules+22].out_fuzzy_set = out_ps;
	fl->rules[no_of_theta_rules+23].out_fuzzy_set = out_nm;
	fl->rules[no_of_theta_rules+24].out_fuzzy_set = out_nvl;
	return;
}


void initMembershipFunctions(fuzzy_system_rec *fl) {
	// I think we need to add our 5 trapezoidal membership functions to each variable here
	
	fl->inp_mem_fns[in_x][in_nl] = init_trapz (-2.4, -1.2, 0, 0, left_trapezoid);
	/*
	  /----\
	 /		  \
	/		   \
	*/
	fl->inp_mem_fns[in_x][in_ns] = init_trapz (-2.4, -1.2, -1.2, 0, regular_trapezoid);
	/*
	  /----\
	 /		  \
	/		   \
	*/
	fl->inp_mem_fns[in_x][in_ze] = init_trapz (-1.2, 0, 0, 1.2, regular_trapezoid);
	/*
	  /----\
	 /		  \
	/		   \
	*/
	fl->inp_mem_fns[in_x][in_ps] = init_trapz (0, 1.2, 1.2, 2.4, regular_trapezoid);
	/*
	  /-----
	 /		  
	/		   
	*/
	fl->inp_mem_fns[in_x][in_pl] = init_trapz (1.2, 2.4, 0, 0, right_trapezoid);
	
	
   // The X dot membership functions
	fl->inp_mem_fns[in_x_dot][in_nl] = init_trapz (-4.5, -2.0, 0, 0, left_trapezoid);
	fl->inp_mem_fns[in_x_dot][in_ns] = init_trapz (-4.5, -2.0, -2.0, 0, regular_trapezoid);
	fl->inp_mem_fns[in_x_dot][in_ze] = init_trapz (-2.0, 0, 0, 2.0, regular_trapezoid);
	fl->inp_mem_fns[in_x_dot][in_ps] = init_trapz (0, 2.0, 2.0, 4.5, regular_trapezoid);
	fl->inp_mem_fns[in_x_dot][in_pl] = init_trapz (2.0, 4.5, 0, 0, right_trapezoid);

	// The theta membership functions  
	fl->inp_mem_fns[in_theta][in_nl] = init_trapz (-1.04, -0.25, 0, 0, left_trapezoid);
	fl->inp_mem_fns[in_theta][in_ns] = init_trapz (-1.04, -0.25, -0.25, 0, regular_trapezoid);
	fl->inp_mem_fns[in_theta][in_ze] = init_trapz (-0.25, 0, 0, 0.25, regular_trapezoid);
	fl->inp_mem_fns[in_theta][in_ps] = init_trapz (0, 0.25, 0.25, 1.04, regular_trapezoid);
	fl->inp_mem_fns[in_theta][in_pl] = init_trapz (0.25, 1.04, 0, 0, right_trapezoid); 
	
    //The theta dot membership functions 
	fl->inp_mem_fns[in_theta_dot][in_nl] = init_trapz (-0.4, -0.2, 0, 0, left_trapezoid);
	fl->inp_mem_fns[in_theta_dot][in_ns] = init_trapz (-0.4, -0.2, -0.2, 0, regular_trapezoid);
	fl->inp_mem_fns[in_theta_dot][in_ze] = init_trapz (-0.2, 0, 0, 0.2, regular_trapezoid);
	fl->inp_mem_fns[in_theta_dot][in_ps] = init_trapz (0, 0.2, 0.2, 0.4, regular_trapezoid);
	fl->inp_mem_fns[in_theta_dot][in_pl] = init_trapz (0.2, 0.4, 0, 0, right_trapezoid);  	

   return;
}

void initFuzzySystem (fuzzy_system_rec *fl) {

   // Note: The settings of these parameters will depend upon your fuzzy system design
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 50; // change to 25 if we use yamakawa
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 9;
	
	// New experimental values
	int vl, l, m, s;
	vl 	= 158;
	l 		= 120;
	m 		= 80;
	s		= 35;
	
	fl->output_values[out_nvl] = -1*(vl);
	fl->output_values[out_nl] = -1*(l);
	fl->output_values[out_nm] = -1*(m);
	fl->output_values[out_ns] = -1*(s);
	fl->output_values[out_ze] = 0;
	fl->output_values[out_ps] = s;
	fl->output_values[out_pm] = m;
	fl->output_values[out_pl] = l;
	fl->output_values[out_pvl] = vl;
	
   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
   initFuzzyRules(fl);
   initMembershipFunctions(fl);
   return;
}

//////////////////////////////////////////////////////////////////////////////

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ) {
   trapezoid trz;
   trz.a = x1;
   trz.b = x2;
   trz.c = x3;
   trz.d = x4;
   trz.tp = typ;
   switch (trz.tp) {
      case regular_trapezoid:
			trz.l_slope = 1.0/(trz.b - trz.a);
			trz.r_slope = 1.0/(trz.c - trz.d);
			break;
	 
      case left_trapezoid:
			trz.r_slope = 1.0/(trz.a - trz.b);
			trz.l_slope = 0.0;
			break;
	 
      case right_trapezoid:
			trz.l_slope = 1.0/(trz.b - trz.a);
			trz.r_slope = 0.0;
			break;
   }  /* end switch  */
   
   return trz;
}  /* end function */

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
float trapz (float x, trapezoid trz) {
	// This function returns how much membership x has within the given trapezoidal function
   switch (trz.tp) {
      case left_trapezoid:
			if (x <= trz.a)
				return 1.0;
			if (x >= trz.b)
				return 0.0;
			/* a < x < b */
			return trz.r_slope * (x - trz.b);
	 
      case right_trapezoid:
         if (x <= trz.a)
            return 0.0;
         if (x >= trz.b)
            return 1.0;
         /* a < x < b */
			return trz.l_slope * (x - trz.a);
	 
      case regular_trapezoid:
			if ((x <= trz.a) || (x >= trz.d))
				return 0.0;
			if ((x >= trz.b) && (x <= trz.c))
				return 1.0;
			if ((x >= trz.a) && (x <= trz.b))
				return trz.l_slope * (x - trz.a);
			if ((x >= trz.c) && (x <= trz.d))
				return  trz.r_slope * (x - trz.d);
	 }  /* End switch  */
	 
   return 0.0;  /* should not get to this point */
}  /* End function */

//////////////////////////////////////////////////////////////////////////////
float min_of(float values[],int no_of_inps) {
   int i;
   float val;
   val = values [0];
   for (i = 1;i < no_of_inps;i++) {
		if (values[i] < val)
	  val = values [i];
   }
   return val;
}

//////////////////////////////////////////////////////////////////////////////
float fuzzy_system (float inputs[],fuzzy_system_rec fz) {
   int i,j;
   short variable_index,fuzzy_set;
   float sum1 = 0.0,sum2 = 0.0,weight;
   float m_values[MAX_NO_OF_INPUTS];
	
   // Calculates the output using the FIS (fuzzy sets, rules, membership functions)
   for (i = 0;i < fz.no_of_rules;i++) {
      for (j = 0;j < fz.no_of_inputs;j++) {
	   variable_index = fz.rules[i].inp_index[j];
	   fuzzy_set = fz.rules[i].inp_fuzzy_set[j];
	   m_values[j] = trapz(inputs[variable_index],
	       fz.inp_mem_fns[variable_index][fuzzy_set]);
	   } /* end j  */
      
       weight = min_of (m_values,fz.no_of_inputs);
				
       sum1 += weight * fz.output_values[fz.rules[i].out_fuzzy_set];
       sum2 += weight;

   } /* end i  */
    //cout << "\nforce applied to cart: " << sum1/sum2;
 
	
	if (fabs(sum2) < TOO_SMALL) {
      cout << "\r\nFLPRCS Error: Sum2 in fuzzy_system is 0.  Press key: " << endl;
      //~ getch();
      //~ exit(1);
      return 0.0;
   }
   
   return (sum1/sum2);
}  /* end fuzzy_system  */

//////////////////////////////////////////////////////////////////////////////
void free_fuzzy_rules (fuzzy_system_rec *fz) {
   if (fz->allocated){
	   free (fz->rules);
	}
	
   fz->allocated = false;
   return;
}

