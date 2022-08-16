/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula12;

import javax.swing.JOptionPane;

/**
 *
 * @author lucas
 */
public class Aula12 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        float n, s=0, total=-1, par=-1, impar=0, acimadecem=0, media=0;
        do {
            n = Integer.parseInt(JOptionPane.showInputDialog(null, 
                    "<html>Informe um número: <br><em>(valor 0 interrompe)</em></html> "));
            s += n;
            total++;    
            if (n%2==0){
                par++; 
        }   else {
                impar++;
        }
            if (n>=100){
                acimadecem++;
        }
        
        } while(n !=0);
        media = s/total;
        JOptionPane.showMessageDialog(null, "<html>Resultado:<br><hr>" + "Total de valores: "+ total
        + "<br>Total de pares: "+ par +"<br>Total de ímpares: "+ impar +"<br>Acima de 100: "+ acimadecem +
                "<br>Soma dos valores: " + s + "<br>Média dos valores: "+ media);
    }
    
}
