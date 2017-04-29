namespace Repaso2doParcial
{
    partial class FrmFinal
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.BtnGeneral = new System.Windows.Forms.Button();
            this.BtnEspecialista = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // BtnGeneral
            // 
            this.BtnGeneral.Location = new System.Drawing.Point(13, 23);
            this.BtnGeneral.Name = "BtnGeneral";
            this.BtnGeneral.Size = new System.Drawing.Size(380, 81);
            this.BtnGeneral.TabIndex = 0;
            this.BtnGeneral.Text = "Atender Medico General";
            this.BtnGeneral.UseVisualStyleBackColor = true;
            this.BtnGeneral.Click += new System.EventHandler(this.BtnGeneral_Click);
            // 
            // BtnEspecialista
            // 
            this.BtnEspecialista.Location = new System.Drawing.Point(13, 110);
            this.BtnEspecialista.Name = "BtnEspecialista";
            this.BtnEspecialista.Size = new System.Drawing.Size(380, 83);
            this.BtnEspecialista.TabIndex = 1;
            this.BtnEspecialista.Text = "Atender medico especialista";
            this.BtnEspecialista.UseVisualStyleBackColor = true;
            this.BtnEspecialista.Click += new System.EventHandler(this.BtnEspecialista_Click);
            // 
            // FrmFinal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(405, 203);
            this.Controls.Add(this.BtnEspecialista);
            this.Controls.Add(this.BtnGeneral);
            this.Name = "FrmFinal";
            this.Text = "Repaso 2do parcial";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FrmFinal_Closing);
            this.Load += new System.EventHandler(this.FrmFinal_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button BtnGeneral;
        private System.Windows.Forms.Button BtnEspecialista;
    }
}

