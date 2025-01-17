	AREA |.TEXT|,CODE,READONLY,ALIGN=2
	THUMB
	EXTERN currentPt
	EXPORT osSchedulerLaunch	
	
osSchedulerLaunch
	LDR R0, =currentPt
	LDR R2, [R0]
	
	LDR SP, [R2]
	POP {R4-R11}
	POP {R0-R3}
	POP {R12}
	ADD SP, SP, #4
	POP {LR}
	ADD SP, SP, #4
	
	CPSIE I
	BX LR
	