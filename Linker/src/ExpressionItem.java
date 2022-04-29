import java.util.ArrayList;
import java.util.Stack;

enum OperandType {
	UNKNOWN, SYMBOL, CONSTANT, OFFSET;
}

enum OperatorType {
	OP_EXP, OP_MUL, OP_DIV, OP_MOD, OP_SHR, OP_SHL, OP_ADD, OP_SUB, OP_AND, OP_OR, OP_XOR, OP_EQ, OP_GT, OP_LT, OP_UGT,
	OP_ULT, OP_LAST, UNKNOWN;

	public int intValue() {
		if (this == UNKNOWN) {
			return 0;
		}
		return this.ordinal() + 20;
	}

	public OperatorType getByValue(int value) {
		for (OperatorType o : OperatorType.values()) {
			if (value == o.intValue())
				return o;
		}
		return OperatorType.UNKNOWN;
	}
}

public class ExpressionItem {

	private OperandType operandType;
	private OperatorType operatorType;
	private Symbol symbol;
	private int value;
	private Section section;
	private int increment;
	private int operands;
	private ExpressionItem next;

	public int getOperands() {
		return operands;
	}

	public void setOperands(int operands) {
		this.operands = operands;
	}

	public OperandType getOperandType() {
		return operandType;
	}

	public void setOperandType(OperandType operandType) {
		this.operandType = operandType;
	}

	public OperatorType getOperatorType() {
		return operatorType;
	}

	public void setOperatorType(OperatorType operatorType) {
		this.operatorType = operatorType;
	}

	public ExpressionItem getNext() {
		return next;
	}

	public void setNext(ExpressionItem next) {
		this.next = next;
	}

	public int getIncrement() {
		return increment;
	}

	public void setIncrement(int increment) {
		this.increment = increment;
	}

	public Symbol getSymbol() {
		return symbol;
	}

	public void setSymbol(Symbol symbol) {
		this.symbol = symbol;
	}

	public int getValue() {
		return value;
	}

	public void setValue(int value) {
		this.value = value;
	}

	public Section getSection() {
		return section;
	}

	public void setSection(Section section) {
		this.section = section;
	}

	private OperandType int2OperandType(int t) throws Exception {
		switch (t) {
		case 1:
			return OperandType.SYMBOL;
		case 2:
			return OperandType.CONSTANT;
		case 3:
			return OperandType.OFFSET;
		default:
			return OperandType.UNKNOWN;
		}
	}

	private OperatorType int2OperatorType(int t) throws Exception {
		switch (t) {
		case 0x15:
			return OperatorType.OP_MUL;
		case 0x16:
			return OperatorType.OP_DIV;
		case 0x18:
			return OperatorType.OP_SHR;
		case 0x19:
			return OperatorType.OP_SHL;
		case 0x1a:
			return OperatorType.OP_ADD;
		case 0x1b:
			return OperatorType.OP_SUB;
		default:
			return OperatorType.UNKNOWN;
		}
	}

	@Override
	public String toString() {
		switch (getOperandType()) {
		case SYMBOL:
			return "sym " + getValue() + "(" + ((getSymbol()==null)?"":getSymbol().toString()) + ")";
		case CONSTANT:
			return "#" + getValue();
		case OFFSET:
			return "off " + getSection() + ":" + getValue();
		default:
			if (isOperator()) {
				return getOperatorType().toString();
			}
			return null;
		}

	}

	public boolean isOperator() {
		if (getOperatorType() != OperatorType.UNKNOWN) {
			return true;
		}

		return false;
	}

	public boolean isOperand() {
		if (getOperandType() != OperandType.UNKNOWN) {
			return true;
		}

		return false;
	}

	public boolean isSymbol() {
		if (getOperandType() == OperandType.SYMBOL) {
			return true;
		}

		return false;
	}

	public boolean isOffset() {
		if (getOperandType() == OperandType.OFFSET) {
			return true;
		}

		return false;
	}

	public void compute(Stack<Integer> stack) throws Exception {

		int op2 = stack.pop();
		int op1 = stack.pop();

		switch (this.getOperatorType()) {
		case OP_ADD:
			stack.push(op1 + op2);
			break;
		case OP_DIV:
			stack.push(op1 / op2);
			break;
		case OP_MUL:
			stack.push(op1 * op2);
			break;
		case OP_SHL:
			stack.push(op1 << op2);
			break;
		case OP_SHR:
			stack.push(op1 >> op2);
			break;
		case OP_SUB:
			stack.push(op1 - op2);
			break;
		case UNKNOWN:
		default:
			throw new Exception("unkown operator");
		}

	}

	public byte[] getBytes() {
		ByteHolder b = new ByteHolder();
		
		switch (this.getOperandType()) {
		case OFFSET:
			b.add((byte) (this.getOperandType().ordinal() & 0xff));
			b.add((byte) (this.getSection().ordinal() & 0xff));			
			b.add(Helper.int2long(this.getValue()));
			break;
			
		case CONSTANT:
			b.add((byte) (this.getOperandType().ordinal() & 0xff));
			b.add(Helper.int2long(this.getValue()));
			break;
		case SYMBOL:
			b.add((byte) (this.getOperandType().ordinal() & 0xff));
			b.add(Helper.int2word(this.getValue()));
			break;
		default:
			b.add(this.getOperatorType().intValue());
			break;
		}

		return Helper.getBytes(b);
	}

	public ExpressionItem(byte[] b, int offset) throws Exception {

		setOperandType(int2OperandType(b[offset] & 0xff));
		setOperatorType(int2OperatorType(b[offset] & 0xff));

		switch (getOperandType()) {
		case SYMBOL:
			setValue(Helper.word2int(b, offset + 1));
			setIncrement(3);
			break;
		case CONSTANT:
			setValue(Helper.long2int(b, offset + 1));
			setIncrement(5);
			break;
		case OFFSET:
			setSection(Section.getByOrdinal(b[offset + 1] & 0xff));
			setValue(Helper.long2int(b, offset + 2));
			setIncrement(6);
			break;
		default:
			if (getOperatorType() == OperatorType.UNKNOWN) {
				throw new Exception("no operand or operator found!");
			}

			setIncrement(1);
			setOperands(2);
			break;
		}

		setNext(null);
	}
}
