extern void populate(struct cell world[size][size]);
extern void printWorld(struct cell world[size][size]);
extern void overwriteCurrent(struct cell world_A[size][size], struct cell world_B[size][size]);
extern void genToFile(struct cell world[size][size]);
extern void statToFile(struct cell world[size][size]);
extern void *cellUpdate(void *var);
