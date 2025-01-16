phase_6{
    r13 = rsp
    rsi = rsp
    callq read_six_numbers
    r14 = rsp
    r12d = 0

1114:
    rbp = r13
    eax = *r13
    eax = eax - 1
    if eax <= 5 
        goto 1128
    else
        calll explode_bomb

1128:
    r12d = r12d + 1
    if 6 == r12d
        goto 1153
    ebx =r12d
       
1135:
    rax = ebx
    eax = *(rsp +4*rax)
    if eax != *rbp 
        goto  1145
    else
        call explode_bomb

1145:
    ebx = ebx + 1
    if ebx <= 5
        goto 1135
    r13 = r13 + 4
    goto 1114

1153:
    rsi = rsp +0x18
    rax = r14
    ecx = 7

1160:
    edx = ecx
    eax -= *rax
    *rax = edx
    rax += 4
    if rax != rsi
        goto 1160

    rsi = 0
    goto 1197

1176:
    rdx = *(rdx + 8)
    eax += 1
    if eax != ecx
        goto 1176
    else
        goto 1188
1183:
    edx = 0x6032d0

1188:
    *(rsp+20+2*rsi) = edx
    rsi = rsi + 4
    if rsi == 0x18
        goto 11ab

1197:
    ecx = *(rsp + rsi)
    if ecx <= 1
        goto 1183
    eax = 1
    edx = 0x6032d0
    goto 1176

11ab:
    rbx = *(rsp + 0x20)
    rax = *(rsp + 0x28)
    rsi = *(rsp + 0x50)
    rcx = rbx

11bd:
    rdx = *(rax)
    *(rcx + 8) = rdx
    rax = rax + 8
    if rsi == rax
        goto 11d2
    rcx = rdx
    goto 11bd
11d2:
    *(rdx + 8) = 0
    ebp = 5

11df:
    rax = *(rbx + 8)
    eax = *(rax)
    if *(rbx) >= eax:
        goto 11ee
    else
        call explode_bomb
11ee:
    rbx = *(rbx + 8)
    ebp = ebp - 1
    if ebp != 0
        goto 11df
    

phase_6(rdi)
{
	r13 = rsp;
	rsi = rsp;
	read_six_numbers(rdi, rsi);
	r14 = rsp;
    for (r12 = 0; r12 != 6; r12++) {
        rbp = r13;
        eax = *r13;
        eax -= 1;
        if (eax > 5)
            explode_bomb();
        for (ebx = r12+1; ebx <= 5; ebx++) {
            rax = ebx;
            eax = *(rsp+rax*4);
            if (*rbp == eax)
                explode_bomb();
        }
        r13 += 4;
    }
    
	rsi = rsp + 0x18;
	rax = r14;
	ecx = 7;
	for (rax = r14; rax != rsi; rax += 4) {
        edx = ecx;
        edx -= *rax;
        *rax = edx;
	}
	
	for (rsi = 0; rsi != 0x18; rsi += 4) {
        ecx = *(rsp+rsi);
        if (ecx <= 1)
            edx = 0x6032d0;
        else {
            edx = 0x6032d0;
            for (eax = 1; eax != ecx; eax++) {
                rdx = *(rdx+8);
            }
        }
        *(rsp+2*rsi+0x20) = rdx;
	}

    rbx = *(rsp+0x20);
    rcx = rbx;
    for (rax = rsp+0x28; rax != rsp+0x50; rax += 8) {
        rdx = *rax;
        *(rcx+8) = rdx;
        rcx = rdx; 
    }

	*(rdx+8) = 0;
	for (ebp = 5; ebp != 0; ebp -= 1) {
		rax = *(rbx+0x8);
        eax = *rax;
        if(eax > *(rbx))
            explode_bomb();
        rbx = *(rbx+8);
	}

    

typedef struct {
    int val;
    ListNode* next;
} ListNode;

void phase_6(char* output)
{
    int array[6];
    ListNode* node_array[6];
    read_six_numbers(output, array);
    // 数字范围必须为1-6且互不重复
    for (int i = 0; i != 6; i++) {
        int num = array[i];
        num--;
        if ((unsigned int)num > 5)		// 最大为6
            explode_bomb();
        for (int j = i+1; j <= 5; j++) {
            if (array[i] == array[j])	// 每个元素都不重复
                explode_bomb();
        }
    }
    // 修改 array
	for (int i = 0; i < 6; i ++) {
        array[i] = (7 - array[i]);
	}
    // 生成 node_array
	for (int i = 0; i < 6; i ++) {
        int cur = array[i];
        ListNode* node = 0x6032d0;		// 链表head
        if (cur > 1) {
            for (int j = 1; j < cur; j++) {
                node = node->next;
            }
        }
        node_array[i] = node;
	}
    for (int i = 0; i < 5; i++) {
        node_array[i]->next = node_array[i+1];
    }
    //0x6032d0 0x6032e0 0x6032f0 0x603300 0x603310 0x603320
    //332 168 924 691 477 443
    // 6 5 4 3 2 1
    ListNode* ptr = node_array[0];
    for (int i = 5; i > 0; i--) {
        if (ptr->val < ptr->next->val)
            explode_bomb();
        ptr = ptr->next;
    }
}
