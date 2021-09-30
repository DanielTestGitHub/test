package Modelo;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Modelo extends ConexionBD {

    public Modelo() {
    }

    public ArrayList<Producto> cosultar() {

        String sql = "SELECT * from productos;";
        ArrayList<Producto> productos = new ArrayList<Producto>();

        ResultSet rst = consultarBD(sql);

        try {
            while (rst.next()) {

                Producto producto = new Producto();
                producto.setId(rst.getInt("id"));
                producto.setNombre(rst.getString("nombre"));
                producto.setCantidad(rst.getInt("cantidad"));
                producto.setCategoria(rst.getString("categoria"));
                producto.setPrecio(rst.getDouble("precio"));

                productos.add(producto);

            }
        } catch (SQLException ex) {
            Logger.getLogger(Modelo.class.getName()).log(Level.SEVERE, null, ex);
        }

        return productos;
    }

    public boolean guardar(Producto producto) {

        String sql = "INSERT INTO productos (nombre,cantidad,categoria,precio) VALUES ('" + producto.getNombre() + "'," + producto.getCantidad() + ",'" + producto.getCategoria() + "'," + producto.getPrecio() + ");";

        if (insertarBD(sql)) {
            System.out.println("Insertado con exito!!!");
            return true;
        } else {
            System.out.println("No se pudo insertar el producto a la BD");
            return false;
        }

    }

    public boolean eliminar(int id) {

        String sql = "DELETE FROM productos WHERE id = " + id + ";";

        if (borrarBD(sql)) {
            System.out.println("Borrado con exito!!!");
            return true;
        } else {
            System.out.println("No se pudo borrar el producto a la BD");
            return false;
        }

    }

    public boolean actualizar(Producto producto) {

        String sql = "UPDATE productos set nombre = '"
                + producto.getNombre() + "'" + ",cantidad = "
                + producto.getCantidad() + ",categoria = '"
                + producto.getCategoria() + "',precio = "
                + producto.getPrecio() + " WHERE id = "
                + producto.getId() + ";";

        if (actualizarBD(sql)) {
            System.out.println("Actualiado con exito!!!");
            return true;
        } else {
            System.out.println("No se pudo actualizar el producto a la BD");
            return false;
        }
    }

}
