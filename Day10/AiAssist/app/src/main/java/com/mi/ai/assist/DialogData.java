package com.mi.ai.assist;


enum FromType {
    me,
    ai
}

public class DialogData {
    public String content;
    public FromType fromType;
    public int type = 0;
    public int time = 0;
}

class AnswerData {
    public String answer = "";
    public float time = 0;
}

class QuestionData {
    public String question = "";
    public long time = 0;
}
