package oo;

import javax.swing.JOptionPane;

public class pp {
	private String name;
	private String account;
	private String data;
	private String ID;
	private double balance;
	private String sercet;

	public pp(String name, double balance, String data, String ID,String se) {
		this.name = name;
		this.balance = balance;
		this.data = data;
		this.ID = ID;
		this.sercet=se;
	}

	public String getaccount() {
		this.account = String.valueOf((int) (Math.random() * 100000) + 1);
		return account;
	}

	public String getdata() {
		return data;
	}

	public String getID() {
		return ID;
	}

	public String getName() {
		return name;
	}
	public String getsercet() {
		return sercet;
	}
  public void setsercet(String nn) {
		this.sercet=nn;
	}
	public double getbalance() {
		return balance;
	}

//查看账户余额
	public double balance() {
		return balance;
	}

//查看开户时间
	public String data() {
		return data;
	}

//存款操作
	public boolean put(double value) {
		if (value > 0) {
			this.balance += value;
			return true;
		}
		return false;
	}

//取款操作
	public double get(double value) {
		if (value > 0) {
			if (value <= this.balance)
				this.balance -= value;
			else {
				value = this.balance;
				this.balance = 0;
			}
			return value;
		}
		return 0;
	}

	public static void main(String args[]) {
		pp user = new pp("李志锐", 2000, "2011/05/23", "362329198906234225","123456");
		String str;
		int b;
		String s = JOptionPane.showInputDialog("您好，存款选择1，取款选择2，查询密码3，修改密码4，退出选择0");
		int x = Integer.parseInt(s);
		while (x != 0) 
		{
			if (x == 1) 
			{
				str = JOptionPane.showInputDialog("输入您要存入的数额");
				b = Integer.parseInt(str);
				if (user.put(b)) 
				{
					JOptionPane.showMessageDialog(null, "请放入钞票！");
					JOptionPane.showMessageDialog(null, "开户账号为" + user.getaccount() + "\n" + user.getName() + "\n开户时间为"
							+ user.data() + "\n您的余额为" + user.balance());
				} 
				else
					JOptionPane.showMessageDialog(null, "你所输入的存款数额有误！");
			}
			else if(x==3)
			{
				//str = JOptionPane.showInputDialog("输入您的账号");
				//b = Integer.parseInt(str);
				JOptionPane.showMessageDialog(null, "开户账号为" + user.getaccount() + "\n" + user.getName() + "\n开户时间为"
						+ user.data() + "\n您的密码为" + user.getsercet());
			}
			else if (x==4) 
			{
				str = JOptionPane.showInputDialog("输入您要修改的密码为");
				user.setsercet(str);
				JOptionPane.showMessageDialog(null, "开户账号为" + user.getaccount() + "\n" + user.getName() + "\n开户时间为"
						+ user.data() + "\n您的密码为" + user.getsercet());
			}
			else 
			{
				str = JOptionPane.showInputDialog("输入您要取出的数额");
				b = Integer.parseInt(str);
				if (b > user.balance()) 
				{
					JOptionPane.showMessageDialog(null, "余额不足");
				} 
				else
				{
					JOptionPane.showMessageDialog(null, "请取出钞票！");
					user.get(b);
					JOptionPane.showMessageDialog(null, "开户账号为" + user.getaccount() + "\n" + user.getName() + "\n开户时间为"
							+ user.data() + "\n您的余额为" + user.balance());
				}
			}
			s = JOptionPane.showInputDialog("您好，存款选择1，取款选择2，查询密码3，修改密码4，退出选择0");
			x = Integer.parseInt(s);
		}
	}
}