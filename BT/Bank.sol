// SPDX-License-Identifier: MIT
pragma solidity >= 0.8.0;

contract Bank{

    mapping(address=>uint) public user_account;
    mapping (address=>bool) public user_exist;

    function create_account() public payable returns(string memory){
           require(user_exist[msg.sender]==false,"User Already Present");
           user_account[msg.sender]=msg.value;
           user_exist[msg.sender]=true;
           return "Account created";
    }

    function deposit(uint amount) public payable returns(string memory){
           require(user_exist[msg.sender]==true,"User not found");
           require(amount > 0,"Enter valid amount");
           user_account[msg.sender]+=amount;
          
           return "Amount Deposited ";
    }

    function withdraw(uint amount) public payable returns(string memory){
           require(user_exist[msg.sender]==true,"User not found");
           require(amount > 0,"Enter valid amount");
           require(user_account[msg.sender] >= amount ,"Enter valid amount");
           user_account[msg.sender]-=amount;
          
           return "Amount Withdrawn ";
    }
    
    function account_balance() public view returns(uint){
        return user_account[msg.sender];
    }

    function account_exit() public view returns(bool){
        return user_exist[msg.sender];
    }

}
