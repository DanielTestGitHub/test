
import Controlador.Controlador;
import Modelo.Modelo;
import Vista.Vista;

public class NewMain {

    public static void main(String[] args) {

        Modelo modelo = new Modelo();
        
        Vista vista = new Vista();
        vista.setVisible(true);
        
        Controlador controller = new Controlador(vista,modelo);
        
        

    }

}
