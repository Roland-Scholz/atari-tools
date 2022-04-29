import java.util.ArrayList;

public class Modules extends ArrayList<Module>{

	private static final long serialVersionUID = -956690788964069623L;

	public Module getBySymbol(Symbol sym, Linkage linkage) {
		for (Module m: this) {
			if (m.getSymbol(sym, linkage) != null) {
				return m;
			}
		}
		return null;
	}
	
	public Module getBySymbolRel(Symbol sym) {
		return getBySymbol(sym, Linkage.S_REL);
	}
	
	public Module getBySymbolUndefined(Symbol sym) {
		return getBySymbol(sym, Linkage.S_UND);
	}
}
