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

//�鿴�˻����
	public double balance() {
		return balance;
	}

//�鿴����ʱ��
	public String data() {
		return data;
	}

//������
	public boolean put(double value) {
		if (value > 0) {
			this.balance += value;
			return true;
		}
		return false;
	}

//ȡ�����
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
		pp user = new pp("��־��", 2000, "2011/05/23", "362329198906234225","123456");
		String str;
		int b;
		String s = JOptionPane.showInputDialog("���ã����ѡ��1��ȡ��ѡ��2����ѯ����3���޸�����4���˳�ѡ��0");
		int x = Integer.parseInt(s);
		while (x != 0) 
		{
			if (x == 1) 
			{
				str = JOptionPane.showInputDialog("������Ҫ���������");
				b = Integer.parseInt(str);
				if (user.put(b)) 
				{
					JOptionPane.showMessageDialog(null, "����볮Ʊ��");
					JOptionPane.showMessageDialog(null, "�����˺�Ϊ" + user.getaccount() + "\n" + user.getName() + "\n����ʱ��Ϊ"
							+ user.data() + "\n�������Ϊ" + user.balance());
				} 
				else
					JOptionPane.showMessageDialog(null, "��������Ĵ����������");
			}
			else if(x==3)
			{
				//str = JOptionPane.showInputDialog("���������˺�");
				//b = Integer.parseInt(str);
				JOptionPane.showMessageDialog(null, "�����˺�Ϊ" + user.getaccount() + "\n" + user.getName() + "\n����ʱ��Ϊ"
						+ user.data() + "\n��������Ϊ" + user.getsercet());
			}
			else if (x==4) 
			{
				str = JOptionPane.showInputDialog("������Ҫ�޸ĵ�����Ϊ");
				user.setsercet(str);
				JOptionPane.showMessageDialog(null, "�����˺�Ϊ" + user.getaccount() + "\n" + user.getName() + "\n����ʱ��Ϊ"
						+ user.data() + "\n��������Ϊ" + user.getsercet());
			}
			else 
			{
				str = JOptionPane.showInputDialog("������Ҫȡ��������");
				b = Integer.parseInt(str);
				if (b > user.balance()) 
				{
					JOptionPane.showMessageDialog(null, "����");
				} 
				else
				{
					JOptionPane.showMessageDialog(null, "��ȡ����Ʊ��");
					user.get(b);
					JOptionPane.showMessageDialog(null, "�����˺�Ϊ" + user.getaccount() + "\n" + user.getName() + "\n����ʱ��Ϊ"
							+ user.data() + "\n�������Ϊ" + user.balance());
				}
			}
			s = JOptionPane.showInputDialog("���ã����ѡ��1��ȡ��ѡ��2����ѯ����3���޸�����4���˳�ѡ��0");
			x = Integer.parseInt(s);
		}
	}
}