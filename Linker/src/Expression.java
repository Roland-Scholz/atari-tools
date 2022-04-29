import java.util.ArrayList;
import java.util.Stack;

public class Expression {

	private int increment;
	private int codeLength;
	private int offset;
	private Section section;
	private ExpressionItem list;

	public Section getSection() {
		return section;
	}

	public void setSection(Section section) {
		this.section = section;
	}

	public int getOffset() {
		return offset;
	}

	public void setOffset(int codeOffset) {
		this.offset = codeOffset;
	}

	public int getIncrement() {
		return increment;
	}

	public void setIncrement(int increment) {
		this.increment = increment;
	}

	public int getCodeLength() {
		return codeLength;
	}

	public void setCodeLength(int codeLength) {
		this.codeLength = codeLength;
	}

	public ExpressionItem getList() {
		return list;
	}

	public void setList(ExpressionItem list) {
		this.list = list;
	}
	
	//   LEN
	// EX   SYM 1    SYM 2     -  END
	// F1 01 01 01 00 01 02 00 1B 00
	// 3F 2 : expr: 1 :| sym 1 | sym 2 | SUB |

	// F1 02 01 01 00 01 02 00 1B 02 01 00 00 00 1A 00
	// 4C B : expr: 2 :| sym 1 | sym 2 | SUB | #1 | ADD |

	// F1 02 01 01 00 00
	// 8CE 9 : expr: 2 :| sym 1 |

	// F1 02 01 02 00 00
	// 8DA 10 : expr: 2 :| sym 2 |

	// F1 02 01 01 00 02 1C 00 00 00 1A 00
	//

	// F1 02 03 04 28 00 00 00 00
	// 53 14 : expr: 2 :| off 4:40 |

	// F1 02 03 01 00 00 00 00 00
	// 5E 11 : expr: 2 :| off 1:0 |

	// F1 02 03 01 2F 00 00 00 02 01 00 00 00 1B 00
	// 7E 25 : expr: 2 :| off 1:47 | #1 | SUB |

	// F1 02 03 01 2D 00 00 00 02 01 00 00 00 1B 00
	// 90 29 : expr: 2 :| off 1:45 | #1 | SUB |

	// F1 02 03 01 2F 00 00 00 02 01 00 00 00 1B 00
	// 9F 2B : expr: 2 :| off 1:47 | #1 | SUB |

	private ExpressionItem addObject(ExpressionItem item, ExpressionItem o) {
		if (item == null) {
			setList(o);
		} else {
			item.setNext(o);
		}

		return o;
	}

	@Override
	public String toString() {
		StringBuilder s = new StringBuilder();

		s.append("expr: ");
		s.append("Length:" + getCodeLength());
		s.append(" TSection:" + getSection());
		s.append(" offset:" + getOffset());
		
		s.append(" :| ");

		ExpressionItem ei = list;

		while (ei != null) {

			s.append(ei.toString());
			s.append(" | ");

			ei = ei.getNext();
		}

		return s.toString();
	}

	public void linkSymbols(Symbols symbols) {
		ExpressionItem ei = getList();

		while (ei != null) {
			if (ei.isSymbol()) {
				ei.setSymbol(symbols.get(ei.getValue()));
			}

			ei = ei.getNext();
		}
	}

	public Reloc eval() throws Exception {

		Stack<Integer> stack = new Stack<Integer>();
		Reloc r = new Reloc();

		r.setTargetSection(this.getSection());
		r.setTargetOffset(this.getOffset());
		r.setCodeLength(this.getCodeLength());

		ExpressionItem ei = this.getList();

		while (ei != null) {
			switch (ei.getOperandType()) {
			case CONSTANT:
				stack.push(ei.getValue());
				break;
			case OFFSET:
				stack.push(ei.getValue());
				r.setSection(ei.getSection());
				break;
			case SYMBOL:
				r.setSymbol(ei.getSymbol());
				r.setSection(ei.getSymbol().getSection());
				stack.push(ei.getSymbol().getOffset());
				break;
			default:
				ei.compute(stack);
			}

			ei = ei.getNext();
		}

		r.setOffset(stack.pop());

		return r;
	}

	public Expression() {
		setIncrement(0);
		setList(null);
		setCodeLength(0);
	}

	public byte[] getBytes() {
		return getByteHolder().getBytes();
	}
	
	public ByteHolder getByteHolder() {
		
		ByteHolder b = new ByteHolder();

		ExpressionItem ei = getList();
		
		b.add(0);							//length of expression
		b.add(getCodeLength());				//length of code to be written
		b.add(getSection().ordinal());
		b.add4(getOffset());
		
		while (ei != null) {
			b.add(ei.getBytes());
			ei = ei.getNext();
			//if (ei != null) b.remove(b.size()-1);
		}		
		
		b.set(0, (byte)(b.size()-1 & 0xff));

		return b;
	}
	
	public Expression(byte[] b, int offset, int codeOffset, Section section) throws Exception {

		setSection(section);
		setOffset(codeOffset);
		setCodeLength(b[offset] & 0xff);
		offset++;

		ExpressionItem item = getList();

		while (b[offset] != 0) {

			item = addObject(item, new ExpressionItem(b, offset));

			offset += item.getIncrement();
			this.increment += item.getIncrement();
		}

		// codeLength + trailing zero
		this.increment += 2;
	}
}
