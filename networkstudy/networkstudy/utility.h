#pragma once

class utility
{
public:
	utility(void);
	~utility(void);

public:
	static BOOL  getLocalAddress(char *sLocalIP, unsigned char  MacAddr[6]);
};
