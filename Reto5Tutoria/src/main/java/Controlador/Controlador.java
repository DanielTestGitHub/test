package Controlador;

import Modelo.Modelo;
import Modelo.Producto;
import Vista.Vista;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.table.DefaultTableModel;

public class Controlador implements ActionListener {

    private Vista vista;
    private Modelo modelo;

    public Controlador(Vista vista, Modelo modelo) {
        this.vista = vista;
        this.modelo = modelo;
        this.vista.btnGuardar.addActionListener(this);
        this.vista.btnActualizar.addActionListener(this);
        this.vista.btnEliminar.addActionListener(this);
        this.vista.btnConsulta.addActionListener(this);

    }

    @Override
    public void actionPerformed(ActionEvent e) {

        JButton actionSource = (JButton) e.getSource();
        DefaultTableModel model = (DefaultTableModel) vista.tablaProductos.getModel();

        if (actionSource.equals(vista.btnGuardar)) {

            Producto producto = new Producto();

            producto.setNombre(vista.txtNombreRegistro.getText());
            producto.setCantidad(Integer.valueOf(vista.txtCantidadRegistro.getText()));
            producto.setCategoria(vista.comboCategoriaRegistro.getSelectedItem().toString());
            producto.setPrecio(Double.valueOf(vista.txtPrecioRegistro.getText()));

            modelo.guardar(producto);

            System.out.println("Guardado");
        } else if (actionSource.equals(vista.btnConsulta)) {

            model.setRowCount(0);
            modelo.cosultar().forEach((producto) -> {
                model.addRow(new Object[]{producto.getId(), producto.getNombre(), producto.getCantidad(), producto.getCategoria(), producto.getPrecio()});

            });

            System.out.println("Consultando...");
        } else if (actionSource.equals(vista.btnEliminar)) {

            modelo.eliminar((int) vista.tablaProductos.getValueAt(vista.tablaProductos.getSelectedRow(), 0));

            model.setRowCount(0);
            modelo.cosultar().forEach((producto) -> {
                model.addRow(new Object[]{producto.getId(), producto.getNombre(), producto.getCantidad(), producto.getCategoria(), producto.getPrecio()});

            });

            System.out.println("Eliminando...");
        } else if (actionSource.equals(vista.btnActualizar)) {
            
            Producto producto = new Producto();
            
            
            producto.setId(Integer.valueOf(vista.txtIdConsulta.getText()));
            producto.setNombre(vista.txtNombreConsulta.getText());
            producto.setCantidad(Integer.valueOf(vista.txtCantidadConsulta.getText()));
            producto.setCategoria(vista.comboCategoriaConsulta.getSelectedItem().toString());
            producto.setPrecio(Double.valueOf(vista.txtPrecioConsulta.getText()));
            
            
            modelo.actualizar(producto);
            
             model.setRowCount(0);
            modelo.cosultar().forEach((product) -> {
                model.addRow(new Object[]{product.getId(), product.getNombre(), product.getCantidad(), product.getCategoria(), product.getPrecio()});

            });
            
            
            System.out.println("Actualizando...");
        }

    }

}
