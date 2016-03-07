bool isMatch(char* s, char* p) {
    //判断为空的情况
    if(p[0] == '\0'){
        return s[0] == '\0';
    }
    //处理'*'匹配，必须假设当前串的第二个字符为'*'，第一个不可能为'*'，因为'*'是和左边第一个作用的
    if(p[1] == '*'){
        //判断原串前面的字符是否是和'*'前面的重复匹配，此时只移动原串，不移动匹配串
        while(s[0] != '\0' && (p[0] == '.' || s[0] == p[0])){
            if(isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    }else{
        //处理非'*'号情况
        if(s[0] != '\0' && (p[0] == '.' || p[0] == s[0])){
            //原串和匹配串同时前进一个字符
            return isMatch(s+1, p+1);
        }
        return false;
    }
}