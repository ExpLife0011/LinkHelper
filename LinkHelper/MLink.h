/*
	需要管理员权限，不然文件夹中的文件不会被链接进去
*/
// MLink.h: interface for the CMLink class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MLINK_H__20089EC1_31D9_48E3_BBD5_3E3C84AE2D4C__INCLUDED_)
#define AFX_MLINK_H__20089EC1_31D9_48E3_BBD5_3E3C84AE2D4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/*

硬链接:
	硬链接就是让多个不在或者同在一个目录下的文件名，同时能够修改同一个文件，其中一个修改后，所有与其有硬链接的文件都一起修改了
	限制：
	1、硬连接适用于在同一个卷的文件级别，不允许给目录创建硬链接;
	2、硬连接是不能跨卷的，只有在同一文件系统中的文件之间才能创建链接。
	硬链接在Windows系统下的应用
	1.节省硬盘空间。同样的文件，只需要维护硬连接关系，不需要进行多重的拷贝，这样可以节省硬盘空间。
	2.重命名文件。重命名文件并不需要打开该文件，只需改动某个目录项的内容即可。
	3.删除文件。删除文件只需将相应的目录项删除，该文件的链接数减1,如果删除目录项后该文件的链接数为零，这时系统才把真正的文件从磁盘上删除。
	4.文件更新。如果涉及文件更新，只需要先在WinSxS目录里面下载好一个新版本，然后修改Windows\System32下面同名文件的硬连接关系，从旧版本的硬连接指向新版本的硬连接，这样就能够快速的完成文件的更新工作，而不需要进行文件的复制，速度也会快不少。
	5.卸载补丁。遇到需要补丁卸载的情况，只需要把硬连接指向改为旧版本就可以了，没有文件替换的问题。而且建立了硬连接关系的文件之间的修改是同步的，因此只要有一方被修改了，另一方也会得到修改。

符号链接：
	符号链接又叫软链接,是一类特殊的文件，这个文件包含了另一个文件的路径名(绝对路径或者相对路径)。
	路径可以是任意文件或目录，可以链接不同文件系统的文件。
	在对符号文件进行读或写操作的时候，系统会自动把该操作转换为对源文件的操作，
	但删除链接文件时，系统仅仅删除链接文件，而不删除源文件本身。

	
	
*/


enum LINKTYPE 
{ 
	HARDLINK, // 文件夹创建失败；文件直接拷贝处理
	SOFTLINKD, // 用来创建文件夹的快捷方式
	SOFTLINKF // 普通文件的快捷方式,文件夹是创建一个无效的文件；
				// 普通文件创建的图标一样，但是无法打开文件
};

class CMLink  
{
public:
	CMLink();
	virtual ~CMLink();
public:
	// 参数一：保存路径和文件名
	// 参数二: 目标文件的完整路径
	BOOL MakeHardLink(TCHAR *linkFileName, TCHAR *existingFileName);
	BOOL MakeSymLink(TCHAR *linkFileName, TCHAR *existingFileName, BOOL dirLink);
 	void makelink(int string_size, TCHAR *variables,enum LINKTYPE type);
	bool MakeLink(TCHAR* pTo, TCHAR* pForm,enum LINKTYPE type);

};

#endif // !defined(AFX_MLINK_H__20089EC1_31D9_48E3_BBD5_3E3C84AE2D4C__INCLUDED_)
