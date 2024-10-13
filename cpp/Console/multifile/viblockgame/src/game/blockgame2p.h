#ifdef SOCKET
#define NETPLAY (game->mode & MODE_NETWORK)
#else
#define NETPLAY 0
#endif

extern struct blockgame2p {
	int falltm;
	int delay;
	char clearedlines[4];
	char nul;
	signed char garbage[3];
	signed char x1, x2;
	short b1, b2;
} blockgame2p[2];

extern struct player *winner;
extern char *tetrom_seq;

void getgarbage_player2();
int nextpiece_2p(struct player *plr);
int startgame_2p();
