// SPDX-License-Identifier: MIT
pragma solidity >= 0.8.0;

contract StudentData{
    struct Student{
        uint id;
        string name;
        uint grade;
    }

    Student [] public students;

    mapping (uint => bool) private student_exist;

    event StudentAdd(uint id,string name,uint grade);

    function addStudent(uint _id, string memory _name, uint _grade) public {
        require(!student_exist[_id],"Student exist");
        Student memory newStudent=Student(_id,_name,_grade);
        students.push(newStudent);
        student_exist[_id]=true;
        emit StudentAdd(_id,_name,_grade);
    }

    function getStudent(uint _index) public view returns(uint, string memory,uint){
        require(_index<students.length,"Invalid");
        Student memory s=students[_index];
        return (s.id,s.name,s.grade);
    }

    fallback() external payable {
        
     }

     receive() external payable { 
        
     }
}