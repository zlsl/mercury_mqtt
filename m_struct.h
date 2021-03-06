#define TARRIF_NUM	2	
#define UInt16		uint16_t
#define byte		unsigned char

// ***** Commands
// Test connection
typedef struct {
 	byte	address;
 	byte	command;
 	UInt16	CRC;
} TestCmd;

// Connection initialisaton command
typedef struct {
 	byte	address;
 	byte	command;
 	byte 	accessLevel;
 	byte	password[6];
 	UInt16	CRC;
} InitCmd;

// Connection terminaion command
typedef struct {
 	byte	address;
 	byte	command;
 	UInt16	CRC;
} ByeCmd;

// Power meter parameters read command
typedef struct {
 	byte	address;
	byte	command;	// 8h
	byte	paramId;	// No of parameter to read
	byte	BWRI;
	UInt16 	CRC;
} ReadParamCmd;


typedef struct {
 	byte	address;
	byte	command;	// 8h
	byte	paramId;	// No of parameter to read
	UInt16 	CRC;
} ReadParamCmd2;


// ***** Results
// 1-byte responce (usually with status code)
typedef struct {
	byte	address;
	byte	result;
	UInt16	CRC;
} Result_1b;

// 3-byte responce
typedef struct {
	byte	address;
	byte	res[3];
	UInt16	CRC;
} Result_3b;

// Result with 3 bytes per phase
typedef struct {
	byte	address;
	byte	p1[3];
	byte	p2[3];
	byte	p3[3];
	UInt16	CRC;
} Result_3x3b;

// Result with 3 bytes per phase plus 3 bytes for phases sum
typedef struct {
	byte	address;
	byte	sum[3];
	byte	p1[3];
	byte	p2[3];
	byte	p3[3];
	UInt16	CRC;
} Result_4x3b;

// Result with 4 bytes per phase plus 4 bytes for sum
typedef struct {
	byte	address;
	byte	ap[4];		// active +
	byte	am[4];		// active -
	byte	rp[4];		// reactive +
	byte	rm[4];		// reactive -
	UInt16	CRC;
} Result_4x4b;

// 3-phase vector (for voltage, frequency, power by phases)
typedef struct {
	float	p1;
	float	p2;
	float	p3;
} P3V;

// 3-phase vector (for voltage, frequency, power by phases) with sum by all phases
typedef struct {
	float	sum;
	float	p1;
	float	p2;
	float	p3;
} P3VS;

// Power vector
typedef struct {
	float 	ap;		// active +
	float	am;		// active -
	float 	rp;		// reactive +
	float 	rm;		// reactive -
} PWV;

// Output results block
typedef struct {
	P3V 	U;			// voltage
	P3V	I;			// current
	P3V	A;			// phase angles
	P3VS	C;			// cos(f)
	P3VS	P;			// current active power consumption
	P3VS	S;			// current reactive power consumption
	PWV	PR;			// power counters from reset (all tariffs)
	PWV	PRT[TARRIF_NUM];	// power counters from reset (by tariffs)
	PWV	PY;			// power counters for yesterday
	PWV	PT;			// power counters for today
	float	f;			// grid frequency
} OutputBlock;

