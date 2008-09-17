/* for Agilent 53181A Frequency Counter
 * 02-Apr-2004  Stephanie Allison (saa@slac.stanford.edu)
 */
/******************************************************************************
 *
 * The following define statements are used to declare the names to be used
 * for the dset tables.   
 *
 * NOTE: The dsets are referenced by the entries in the command table.
 *
 *****************************************************************************/
#define	DSET_AI		devAiHp53181AGpib
#define	DSET_AO		devAoHp53181AGpib
#define	DSET_BI		devBiHp53181AGpib
#define	DSET_BO		devBoHp53181AGpib
#define	DSET_SI		devSiHp53181AGpib
#define	DSET_SO		devSoHp53181AGpib

#include <devGpib.h>

/******************************************************************************
 *
 * Use the TIME_WINDOW defn to indicate how long commands should be ignored
 * for a given device after it times out.  The ignored commands will be
 * returned as errors to device support.
 *
 * Use the IO_TIME to define how long you wish to wait for an I/O operation
 * to complete once started.
 *
 *****************************************************************************/
#define TIME_WINDOW	2		
#define	IO_TIME         4


/******************************************************************************
 *
 * String arrays for EFAST operations.	Note that the last entry must be 
 * NULL.
 *
 * On input operations, only as many bytes as are found in the string array
 * elements are compared.	If there are more bytes than that in the input
 * message, they are ignored.	The first matching string found (starting
 * from the 0'th element) will be used as a match.
 *
 * NOTE: For the input operations, the strings are compared literally!	This
 * can cause problems if the instrument is returning things like \r and \n
 * characters.	You must take care when defining input strings so you include
 * them as well.
 *
 *****************************************************************************/

static char *inpAttStrings[]          = { "1\n", "10\n"                 }; 
static char *attStrings[]             = { "1"  , "10"                   };
static struct devGpibNames attNames   = { 2, attStrings,     NULL,    1 };

static char *inpCoupStrings[]         = { "AC\n" , "DC\n"               };
static char *coupStrings[]            = { "AC"   , "DC"                 };
static struct devGpibNames coupNames  = { 2, coupStrings,    NULL,    1 };

static char *inpImpStrings[]          = { "1E6\n"  , "50\n"             };
static char *impStrings[]             = { "1 MOhm" , "50 Ohm"           };
static struct devGpibNames impNames   = { 2, impStrings,     NULL,    1 };

static char *offOnStrings[]           = { "OFF\n", "ON\n"               };
static char *stateStrings[]           = { "OFF"  , "ON"                 };
static struct devGpibNames stateNames = { 2, stateStrings,   NULL,    1 };

/******************************************************************************
 *
 * Array of structures that define all GPIB messages
 * supported for this type of instrument.
 *
 *****************************************************************************/

static struct gpibCmd gpibCmds[] = 
{
  /* Param 0 for general stringout */
  {&DSET_SO, GPIBWRITE ,       IB_Q_LOW, NULL,           "%s\n",
   0,40,NULL,0,0,NULL,NULL,NULL},
  
  /* Param 1 - get channel value */
  {&DSET_AI, GPIBREAD  ,       IB_Q_LOW, "FETCH?\n"     , "%lf",
   0,40,NULL,0,0,NULL,NULL,NULL},
  
  /* Param 2 - get option */
  {&DSET_SI, GPIBREAD  ,       IB_Q_LOW, "*OPT?\n"      , NULL,
   0,40,NULL,0,0,NULL,NULL,NULL},
  
  /* Param 3 */
  FILL,

  /* Param 4 - set freq attenuation */
  {&DSET_BO, GPIBEFASTO,       IB_Q_LOW, "INP:ATT "     , NULL,
   0,40,NULL,0,0, inpAttStrings,   &attNames,   NULL},

  /* Param 5 - set low-pass filter state */
  {&DSET_BO, GPIBEFASTO,       IB_Q_LOW, "INP:FILT "    , NULL,
   0,40,NULL,0,0, offOnStrings,    &stateNames, NULL},

  /* Param 6 - set input coupling */
  {&DSET_BO, GPIBEFASTO,       IB_Q_LOW, "INP:COUP "    , NULL,
   0,40,NULL,0,0, inpCoupStrings,  &coupNames,  NULL},

  /* Param 7 - set input impedance */
  {&DSET_BO, GPIBEFASTO,       IB_Q_LOW, "INP:IMP "     , NULL,
   0,40,NULL,0,0, inpImpStrings,   &impNames, NULL},

  /* Param 8 - get ID */
  {&DSET_SI, GPIBREAD  ,       IB_Q_LOW, "*IDN?\n"      , NULL,
   0,40,NULL,0,0,NULL,NULL,NULL},
  
  /* Param 9 - get error */
  {&DSET_SI, GPIBREAD  ,       IB_Q_LOW, "SYST:ERR?\n"  , NULL,
   0,40,NULL,0,0,NULL,NULL,NULL},
  
};

/* The following is the number of elements in the command array above.  */
#define NUMPARAMS	sizeof(gpibCmds)/sizeof(struct gpibCmd)

/******************************************************************************
 *	Initailization for device support.
 *	This is called one time before any records are initialized with
 *	a parm value of 0. And then again AFTER all record-level init is
 *	complete with a param value of 1.
 *****************************************************************************/
static long init_ai(int parm)
{
    if (parm==0) {
	devSupParms.name="devHp53181AGpib";
	devSupParms.gpibCmds = gpibCmds;
	devSupParms.numparams = NUMPARAMS;
	devSupParms.timeWindow = TIME_WINDOW;
	devSupParms.timeout = IO_TIME;
	devSupParms.respond2Writes = -1;
    }
    return(0);
}
