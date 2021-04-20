// Copyright(c) <2021> <VirusRushTheater>
// The MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

// This is an abridged version of Quake 2 q_shared.h to make cvars work.

#include <stdbool.h>

#ifndef CVAR
#define	CVAR

#define	CVAR_ARCHIVE	1	// set to cause it to be saved to vars.rc
#define	CVAR_USERINFO	2	// added to userinfo  when changed
#define	CVAR_SERVERINFO	4	// added to serverinfo when changed
#define	CVAR_NOSET		8	// don't allow change from console at all,
							// but can be set from the command line
#define	CVAR_LATCH		16	// save changes until server restart

//
// key / value info strings
//
#define	MAX_INFO_KEY		64
#define	MAX_INFO_VALUE		64
#define	MAX_INFO_STRING		512

// nothing outside the Cvar_*() functions should modify these fields!
typedef struct cvar_s
{
	char		*name;
	char		*string;
	char		*latched_string;	// for CVAR_LATCH vars
	int			flags;
	bool	    modified;	// set each time the cvar is changed
	float		value;
	struct cvar_s *next;
} cvar_t;

// Function prototypes
static bool Cvar_InfoValidate(char *s);
static cvar_t *Cvar_FindVar(const char *var_name);
float Cvar_VariableValue(char *var_name);
const char *Cvar_VariableString(const char *var_name);
char *Cvar_CompleteVariable(char *partial);
cvar_t *Cvar_Get(char *var_name, char *var_value, int flags);
cvar_t *Cvar_Set2 (char *var_name, char *value, bool force);
cvar_t *Cvar_ForceSet(char *var_name, char *value);
cvar_t *Cvar_Set(char *var_name, char *value);
cvar_t *Cvar_FullSet(char *var_name, char *value, int flags);
void Cvar_SetValue(char *var_name, float value);
void Cvar_GetLatchedVars(void);
bool Cvar_Command(void);
void Cvar_Set_f(void);
void Cvar_WriteVariables(char *path);
void Cvar_List_f(void);
char *Cvar_BitInfo(int bit);
char *Cvar_Userinfo (void);
char *Cvar_Serverinfo (void);
void Cvar_Init(void);

// Helper methods
#define Com_Printf(A,...) fprintf(stderr, A, __VA_ARGS__)

#endif		// CVAR